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
#include <sstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <cstring>
#include <string>

/**
 * The function parser_str() build a dynamic string based on format argument
 * compound by specifiers and each one has a meaning that will be replaced
 * by a determined value.
 *
 * @param format String containing specifiers with log informations.
 *
 *     %D{<format>}  The date format is based on strftime().
 *                   %a – Abbreviated weekday name
 *                   %A – Full weekday name
 *                   %b – Abbreviated month name
 *                   %B – Full month name
 *                   %c – Standard date and time string
 *                   %d – Day of month as a decimal(1-31)
 *                   %H – Hour(0-23)
 *                   %I – Hour(1-12)
 *                   %j – Day of year as a decimal(1-366)
 *                   %m – Month as decimal(1-12)
 *                   %M – Minute as decimal(0-59)
 *                   %p – Locale's equivalent of AM or PM
 *                   %q – Milliseconds as decimal(0-999) – Special for the application.
 *                   %S – Second as decimal(0-59)
 *                   %U – Week of year, Sunday being first day(0-53)
 *                   %w – Weekday as a decimal(0-6, Sunday being 0)
 *                   %W – Week of year, Monday being first day(0-53)
 *                   %x – Standard date string
 *                   %X – Standard time string
 *                   %y – Year in decimal without century(0-99)
 *                   %Y – Year including century as decimal
 *                   %Z – Time zone name
 *
 *     %F            File where method was invoked.
 *     %M            Method where method was invoked.
 *     %L            Line where method was invoked.
  *
 * @return Returns parsed string with specifiers replaced.
 */
std::string parser_str(const std::string format,
                       const std::string file,
                       const std::string method,
                       const int line) {
    std::cout << "Format: (" << format << ")" << " File: (" << file << ") Method: (" << method << ") Line: (" << line << ")\n";
    bool found_date = false;
    bool found_date_key = false;
    bool found_specifier = false;

    char sv[64];
    std::stringstream ssr;

    std::cout << "sizeof(sv) - sizeof(char): " << sizeof(sv) - sizeof(char) << " size: " << sizeof(sv) << "\n\n";

    auto cur_time = std::chrono::system_clock::now();
    std::time_t cur_time_tt = std::chrono::system_clock::to_time_t(cur_time);
    std::tm * tm = std::localtime(&cur_time_tt);

    for (unsigned int i = 0; i < format.length(); i++) {
        std::cout << "Char: (" << format[i] << ") Pos: (" << i << ") Specifier: (" << found_specifier << ") Found Date: (" << found_date << ") Found Key: (" << found_date_key << ")\n";

        if (format[i] == '{') {
            // Begin of date/time.
            std::cout << "Found begin of date/time!\n";
            found_date_key = true;
            continue;
        } else if (format[i] == '}') {
            // End of date/time.
            std::cout << "Found end of date/time!\n";
            found_date = false;
            found_date_key = false;
            continue;
        } else if (format[i] == '%') {
            found_specifier = true;
            continue;
        } else if (format[i] == 'D') {
            // Date/time specifier.
            std::cout << "Found date/time specifier!\n";
            found_date = true;
            found_specifier = false;
            continue;
        } else if ((found_date == true) &&
                   (found_date_key == true) &&
                   (found_specifier == true) &&
                   (format[i] == 'q')) {
            // Milliseconds specifier.
            std::cout << "Found milliseconds specifier!\n";
            ssr << (cur_time.time_since_epoch().count() / 1000000) % 1000;
            found_specifier = false;
            continue;
        } else if ((found_date == true) &&
                   (found_date_key == true) &&
                   (found_specifier == true)) {
            memset(sv, 0, sizeof(sv));
            std::string tmp("%");
            tmp += format[i];
            std::strftime(sv, (sizeof(sv) - sizeof(char)), tmp.c_str(), tm);
            ssr << sv;
            found_specifier = false;
            continue;
        } else if (format[i] == 'F') {
            // File specifier.
            std::cout << "Found file specifier!\n";
            ssr << file;
            found_specifier = false;
            continue;
        } else if (format[i] == 'M') {
            // Method specifier.
            std::cout << "Found method specifier!\n";
            ssr << method;
            found_specifier = false;
            continue;
        } else if (format[i] == 'L') {
            // Line specifier.
            std::cout << "Found line specifier!\n";
            ssr << line;
            found_specifier = false;
            continue;
        }

        ssr << format[i];

        std::cout << "Iteration: (" << i << ") Result: (" << ssr.str() << ")\n";
    }

    return ssr.str();
}

int main(int argc,
         char * argv[]) {
    // Simple example.
    std::string result1 = parser_str("%D{%Y} [%F]", __FILE__, __PRETTY_FUNCTION__, __LINE__);

    // No D specifier but with begin and end key.
    std::string result2 = parser_str("%{%Y-%m-%d (%F)", __FILE__, __PRETTY_FUNCTION__, __LINE__);

    // No begin keys.
    std::string result3 = parser_str("%D %Y-%m-%d}(%F)", __FILE__, __PRETTY_FUNCTION__, __LINE__);

    // No end keys.
    std::string result4 = parser_str("%D{%Y-%m-%d (%F)", __FILE__, __PRETTY_FUNCTION__, __LINE__);

    // Without both keys.
    std::string result5 = parser_str("%D%Y-%m-%d (%F)", __FILE__, __PRETTY_FUNCTION__, __LINE__);

    // Double begin key.
    std::string result6 = parser_str("%D{{%Y-%m-%d (%F)}", __FILE__, __PRETTY_FUNCTION__, __LINE__);

    // Space between specifiers.
    std::string result7 = parser_str("%   D{ %    Y-%m - %d }     [%F]", __FILE__, __PRETTY_FUNCTION__, __LINE__);

    // Unknown date/time specifier.
    std::string result8 = parser_str("%D{%Y - %m-%d %o} [ %F ]", __FILE__, __PRETTY_FUNCTION__, __LINE__);

    // Final example.
    std::string result9 = parser_str("[%D{%Y-%m-%d %H:%M:%S:%q}][%F][%M][%L]", __FILE__, __PRETTY_FUNCTION__, __LINE__);

    std::cout << "\n--------------------------------------------------------------------------------\n\n";

    std::cout << "Result 1: (" << result1 << ") - (" << ((result1 == "2019 [parsing_specifier.cpp]") ? "OK" : "FAIL") << ")\n";
    std::cout << "Result 2: (" << result2 << ") - (" << ((result2 == "Y-m-d (parsing_specifier.cpp)") ? "OK" : "FAIL") << ")\n";
    std::cout << "Result 3: (" << result3 << ") - (" << ((result3 == " Y-m-d(parsing_specifier.cpp)") ? "OK" : "FAIL") << ")\n";
    std::cout << "Result 4: (" << result4 << ") - (" << ((result4 == "2019-08-28 (2019-08-28)") ? "OK" : "FAIL") << ")\n";
    std::cout << "Result 5: (" << result5 << ") - (" << ((result5 == "Y-m-d (parsing_specifier.cpp)") ? "OK" : "FAIL") << ")\n";
    std::cout << "Result 6: (" << result6 << ") - (" << ((result6 == "2019-08-28 (2019-08-28)") ? "OK" : "FAIL") << ")\n";
    std::cout << "Result 7: (" << result7 << ") - (" << ((result7 == "    %    Y-08 - 28      [parsing_specifier.cpp]") ? "OK" : "FAIL") << ")\n";
    std::cout << "Result 8: (" << result8 << ") - (" << ((result8 == "2019 - 08-28 %o [ parsing_specifier.cpp ]") ? "OK" : "FAIL") << ")\n";
    std::cout << "Result 9: (" << result9 << ")\n";

    return 0;
}