#ifndef XOSHIRO512STARSTAR_HPP
#define XOSHIRO512STARSTAR_HPP

#include <chrono>

/**
 * @brief Class Xoshiro512 implements a pseudo-random number generator using the Xoshiro512starstar algorithm.
 * See more about this algorithm in https://prng.di.unimi.it/xoshiro512starstar.c
 */
class Xoshiro512 {
private:
    static bool is_inicialized; // Flag to indicate if the generator has been initialized
    static uint64_t state[8]; // Array to store the internal state of the generator

    static inline uint64_t rotl(const uint64_t &x, const int &k); // Left rotation function

public:
    /**
     * @brief Default constructor for the Xoshiro512 class.
     */
    Xoshiro512();

    /**
     * @brief Constructor for the Xoshiro512 class that allows initializing the generator with a seed.
     * @param seed The seed value to initialize the generator.
     */
    Xoshiro512(uint64_t seed);

    /**
     * @brief Method to set the seed of the generator.
     * @param seed The seed value to set.
     */
    void setSeed(uint64_t seed);

    /**
     * @brief Method to generate a random 64-bit unsigned integer uniformly distributed in the range 0 to UINT64_MAX.
     * @return A random 64-bit unsigned integer.
     */
    uint64_t getUint64();

    /**
     * @brief Method to generate a random 64-bit unsigned integer within a specified range.
     * @param min The minimum bound of the range.
     * @param max The maximum bound of the range.
     * @return A random 64-bit unsigned integer within the specified range.
     */
    uint64_t getUint64(const uint64_t &min, const uint64_t &max);

    /**
     * @brief Method to generate a random 64-bit signed integer uniformly distributed in the range INT64_MIN to INT64_MAX.
     * @return A random 64-bit signed integer.
     */
    int64_t getInt64();

    /**
     * @brief Method to generate a random 64-bit signed integer within a specified range.
     * @param min The minimum bound of the range.
     * @param max The maximum bound of the range.
     * @return A random 64-bit signed integer within the specified range.
     */
    int64_t getInt64(const int64_t &min, const int64_t &max);

    /**
     * @brief Method to generate a random uniform number in the range [0, 1).
     * @return A random uniform number.
     */
    double getDouble();

    /**
     * @brief Method to generate a random uniform number within a specified range [min, max).
     * @param min The minimum value of the range.
     * @param max The maximum value of the range.
     * @return A random uniform number within the specified range.
     */
    double getDouble(const double &min, const double &max);

};

#endif
