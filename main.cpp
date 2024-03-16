#include "src/Xoshiro512starstar.hpp"
#include <iostream>
#include <fstream>

int main() {

    std::ofstream outputFile("output.txt"); // Open a file for writing output

    // Check if the file was opened correctly
    if (!outputFile.is_open()) {
        std::cerr << "Error opening the output file." << std::endl;
        return 1; // Return 1 to indicate an error
    }

    // Example usage of the random number generator
    Xoshiro512 rng;

    int64_t randomNumber = rng.getInt64(1, 100);
    outputFile << "Random number generated: " << randomNumber << std::endl;

    // Here's where the user can write their own code
    // For example:
    // outputFile << "Result of some calculation: " << someCalculation() << std::endl;

    // Close the file after writing
    outputFile.close();

    std::cout << "Code executed successfully. Check the output file." << std::endl;

    return 0; // Return 0 to indicate success
}
