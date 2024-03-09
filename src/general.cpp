#include "general.hpp"
#include <fstream>

void assertError(bool condition, const std::string& errorMessage) {
    if (!condition) {
        // Register the error in a log file
        std::ofstream errorLog("error_log.log", std::ios::app);
        if (errorLog.is_open()) {
            errorLog << "terminate called after throwing an instance of 'std::runtime_error'\n  what(): " << errorMessage << std::endl;
            errorLog.close();
        }
        
        // Throw an exception to halt the program execution
        throw std::runtime_error(errorMessage);
    }
}

void assertOverflow(bool condition, const std::string& errorMessage) {
    if (!condition) {
        // Register the error in a log file
        std::ofstream errorLog("error_log.log", std::ios::app);
        if (errorLog.is_open()) {
            errorLog << "terminate called after throwing an instance of 'std::overflow_error'\n  what(): " << errorMessage << std::endl;
            errorLog.close();
        }
        
        // Throw an overflow exception
        throw std::overflow_error(errorMessage);
    }
}

void assertLogic(bool condition, const std::string& errorMessage) {
    if (!condition) {
        // Register the error in a log file
        std::ofstream errorLog("error_log.log", std::ios::app);
        if (errorLog.is_open()) {
            errorLog << "terminate called after throwing an instance of 'std::logic_error'\n  what(): " << errorMessage << std::endl;
            errorLog.close();
        }
        
        // Throw a logic exception
        throw std::logic_error(errorMessage);
    }
}
