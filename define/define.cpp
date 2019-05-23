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
#include <sstream>
#include <chrono>
#include <iomanip>
#include <ctime>

#define DEBUG 1
#define INFO 2

#define LOG_DEBUG logger::Log("DEBUG", __FILE__, __LINE__, __PRETTY_FUNCTION__)
#define LOG_INFO logger::Log("INFO", __FILE__, __LINE__, __PRETTY_FUNCTION__)

/*
 * Example of usage of ## and # operators.
 *
 * The ## operator join the argument severity with string "LOG_" calling
 * define LOG_DEBUG or LOG_INFO depending of what goes on LOG() parameter.
 *
 * The # operator join too but the argument is held between double quotes.
 *
 * The Makefile of this test contains -save-temps flag that allows to keep with  
 * preprocessed file, therefore we can see how main() will be, let's take this
 * source as example:
 *
 * int main(int argc, char * argv []) {
 *
 *   logger::Log("DEBUG", "define.cpp", 122, __PRETTY_FUNCTION__).message() << "A debug log record.";
 *   logger::Log("INFO", "define.cpp", 123, __PRETTY_FUNCTION__).message() << "A info log record.";
 *
 *   logger::Log("DEBUG", "define.cpp", 126, __PRETTY_FUNCTION__).message() << "A debug log X record.";
 *
 *   return (0);
 * }
 */
#define LOG(severity) LOG_##severity.message()
#define LOGX(severity) LOG_ ## severity.message() // Ignores the space.

namespace logger {

class Log {

public:
    Log(const std::string severity, 
        const std::string file,
        const int line,
        const std::string function)
        : _severity(severity),
          _file(file),
          _line(line),
          _function(function),
          _timestamp(getCurrentTime()) {
        std::cout << "Calling log constructor!\n";
        std::cout << "Severity: " << severity 
                  << " File: " << file 
                  << " Line: " << line
                  << " Function: " << function << "\n";
    }

    ~Log() {
        std::cout << "Caling log destructor!\n";

        _record << "[" << _timestamp << "][" << _file << "][" << _function << "][" << _line << "][" << _severity << "] - " << _message.str();

        std::cout << "My log record result: " << _record.str() << "\n";
    }

    std::stringstream & message() {
        return _message;
    }

    std::string getCurrentTime() {    
        std::stringstream oTime;

        auto oCurrentTime = std::chrono::system_clock::now();
        std::time_t oCurrentTimeTT = std::chrono::system_clock::to_time_t(oCurrentTime);
        std::tm oCurrentLT = * std::localtime(&oCurrentTimeTT);
        auto aMilliseconds = (oCurrentTime.time_since_epoch().count() / 1000000) % 1000;

        oTime << std::put_time(&oCurrentLT, "%T") << ":" << aMilliseconds;

        return (oTime.str());
    }

private:
    std::stringstream _message;
    std::stringstream _record;
    std::string _severity;
    std::string _file;
    int _line;
    std::string _function;
    std::string _timestamp;

};

} // Logger namespace


int main(__attribute__((unused)) int argc,
         __attribute__((unused)) char * argv []) {

    LOG(DEBUG) << "A debug log record.";
    LOG(INFO) << "A info log record."; 

    LOGX(DEBUG) << "A debug log X record.";

    return (0);
}
