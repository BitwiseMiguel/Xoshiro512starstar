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


// Left rotation function
inline uint64_t Xoshiro512::rotl(const uint64_t &x, const int &k) {
    return (x << k) | (x >> (64 - k));
};

// Method to generate a random 64-bit unsigned integer
uint64_t Xoshiro512::getUint64() {
	const uint64_t result = rotl(state[1] * 5, 7) * 9;

	const uint64_t t = state[1] << 11;

    // State update
	state[2] ^= state[0];
	state[5] ^= state[1];
	state[1] ^= state[2];
	state[7] ^= state[3];
	state[3] ^= state[4];
	state[4] ^= state[5];
	state[0] ^= state[6];
	state[6] ^= state[7];

	state[6] ^= t;

	state[7] = rotl(state[7], 21);

	return result;
};

// Method to generate a random 64-bit unsigned integer within a specified range
uint64_t Xoshiro512::getUint64(const uint64_t &min, const uint64_t &max) {
    #ifdef DEBUG
    // Check if the minimum value is lesser than the maximum value
    assertLogic(min <= max, "The minimum value is greater than the maximum value.");
    #endif
    
    // Generate a random number using the uniform distribution
    auto random = getUint64();
    
    // Check if the range is the entire range of uint64_t
    if (min == 0ULL && max == UINT64_MAX) {
        return random;
    }

    // Calculate the range of the random number
    auto range = max - min + 1ULL;

    // Calculate the remainder range
    auto remainder_range = ((UINT64_MAX % range) + 1ULL) % range;

    // Generate a new random number if it falls within the remainder range
    while (random < remainder_range) {
        random = getUint64();
    }
    
    // Return the generated random number within the specified range
    return min + random % range;
};
