#ifndef GENERAL_HPP
#define GENERAL_HPP

#include <string>

/**
 * Checks a condition and logs an error if the condition is false.
 * @param condition The condition to be checked.
 * @param errorMessage The error message to be logged.
 * @throws std::runtime_error if the condition is false.
 * @remarks This function logs the error message to a log file.
 */
void assertError(bool condition, const std::string& errorMessage);

/**
 * Checks a condition and logs an error if the condition is false.
 * @param condition The condition to be checked.
 * @param errorMessage The error message to be logged.
 * @throws std::overflow_error if an overflow occurs.
 * @remarks This function logs the error message to a log file.
 */
void assertOverflow(bool condition, const std::string& errorMessage);

/**
 * Checks a condition and logs an error if the condition is false.
 * @param condition The condition to be checked.
 * @param errorMessage The error message to be logged.
 * @throws std::logic_error if a logic error occurs.
 * @remarks This function logs the error message to a log file.
 */
void assertLogic(bool condition, const std::string& errorMessage);

#endif
