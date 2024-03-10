#include "general.hpp"
#include "Xoshiro512starstar.hpp"

/*static*/ bool Xoshiro512::is_inicialized{false};
/*static*/ uint64_t Xoshiro512::state[8];

// Default constructor for the Xoshiro512 class
Xoshiro512::Xoshiro512() {
    if (is_inicialized) return;
    // Generate seed based on current time
    auto now = std::chrono::system_clock::now();
    auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
    auto seed = now_ms.time_since_epoch().count();
    setSeed(seed);
    is_inicialized = true;
};

// Constructor for the Xoshiro512 class that allows initializing the generator with a seed
Xoshiro512::Xoshiro512(uint64_t seed) {
    // Set the seed and initialize the flag for normal distribution
    setSeed(seed);
    is_inicialized = true;
};

// Method to set the seed of the generator
void Xoshiro512::setSeed(uint64_t seed) {
    // Splitmix64 random generator
    // See https://rosettacode.org/wiki/Pseudo-random_numbers/Splitmix64
    for (int i = 0; i < 8; i++) {
        seed += 0x9e3779b97f4a7c15;
        uint64_t z = seed;
        z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
        z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
        state[i] = z ^ (z >> 31);
    }
};
