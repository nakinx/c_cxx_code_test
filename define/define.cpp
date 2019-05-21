#include <iostream>
#include <string>

#define DEBUG 1
#define INFO 2

#define LOG_DEBUG logger::Log("DEBUG")
#define LOG_INFO logger::Log("INFO")

/*
 * Example of usage of ## and # operators.
 *
 * The ## operator join the argument severity with string LOG_ calling
 * define LOG_DEBUG or LOG_INFO depending of what goes on parameter.
 *
 * The # operator join but the argument is held between double quotes.
 *
 * The makefile of this test contains -save-temps flag that allows to keep with  
 * preprocessed file, therefore we can see how main() will be:
 *
 * int main(int argc, char * argv []) {
 *
 *   logger::Log("DEBUG").printMsg("DEBUG");
 *   logger::Log("INFO").printMsg("INFO");
 *
 *  return (0);
 * }
 */
#define LOG(severity) LOG_##severity.printMsg(#severity)

namespace logger {

class Log {

public:
    Log(std::string severityLevel) {
        std::cout << "Calling log constructor!\n";
        std::cout << "Severity level: " << severityLevel << "\n";
    }

    ~Log() {
        std::cout << "Caling log destructor!\n";
    }

    void printMsg(const std::string msg) {
        std::cout << msg << "\n";   
    }
};

} // Logger namespace


int main(int argc, char * argv []) {

    LOG(DEBUG);
    LOG(INFO); 

   return (0);
}
