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
#include <string>

std::string rightTrim(std::string & str) {
    return str.erase(str.find_last_not_of(" ") + 1);
}

std::string leftTrim(std::string & str) {
    return str.erase(0, str.find_first_not_of(" "));
}

std::string trim(std::string & str) {    
    str.erase(str.find_last_not_of(" ") + 1);
    return str.erase(0, str.find_first_not_of(" "));
}

int main(int argc,
         char * argv[]) {

    std::string str("    Ismael Filipe    ");

    std::cout << "\nOriginal string: (" << str << ")\n";

    // Remove all white space on the right of the string.
    rightTrim(str);
    std::cout << "\nRight trim in string: (" << str << ")\n";

    // Remove all white space on the left of the string.
    leftTrim(str);
    std::cout << "\nLeft trim in string: (" << str << ")\n";

    // Remove white space from the left and right of the string.
    std::string str2("    nakin    ");
    trim(str2);
    std::cout << "\nTrim string in both sides: (" << str2 << ")\n"; 


    return (0);
}

