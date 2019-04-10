/*
 * MIT License
 *
 * Copyright (c) 2019 Ismael Filipe Mesquita Ribeiro - nakinx
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#include <iostream>
#include <locale>
#include <sstream>

int main (int argc, char * argv[])
{
    if (argc < 2)
    {
        std::cout << "Invalid arguments!" << std::endl << std::endl << "Usage: " << argv[0] << " <value> [<locale>]" << std::endl;		
    	return -1;
    }

    std::cout << "Initiating monetary formatting value application!" << std::endl;

    std::cout << "The value (" << argv[1] << ") will be formatted to monetary pattern." << std::endl;

    std::string oLocaleId;
    
    if (argc == 3)
    	oLocaleId = argv[2];

    std::locale oLocale;

    try
    {
        oLocale = std::locale(oLocaleId.c_str());
    }
    catch (const std::exception & e)
    {
        std::cout << "Invalid locale identification! (" << e.what()  << ")"<< std::endl;
        oLocale = std::locale("");
    }
	   
    std::cout << "Using (" << oLocale.name() << ") as locale identification." << std::endl;

    long double ldValue = 0;
    std::stringstream oSsValue;
    std::stringstream oSsFormattedValue;

    oSsFormattedValue.imbue(oLocale);

    const std::moneypunct<char> &oMoneyPunct = std::use_facet<std::moneypunct<char> >(oSsFormattedValue.getloc());

    const std::money_put<char> & oMoneyPut = std::use_facet<std::money_put<char> >(oSsFormattedValue.getloc());

    // Converting original string to a numeric type.
    oSsValue << argv[1];
    oSsValue >> ldValue;

    // Formatting to monetary using locale as pattern.
    oMoneyPut.put(oSsFormattedValue, false, oSsFormattedValue, ' ', ldValue);


    std::cout << std::endl
              << "Conversion results:" << std::endl << std::endl
              << "Original string: (" << argv[1] << ")" << std::endl
              << "Original numeric value: (" << std::fixed << ldValue << ") " << std::endl
              << "Original formatted string value: (" << oMoneyPunct.curr_symbol() << oSsFormattedValue.str() << ")" << std::endl
              << std::endl << std::endl;


    return 0;
}
