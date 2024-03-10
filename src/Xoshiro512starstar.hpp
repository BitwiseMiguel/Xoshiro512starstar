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

};

#endif
