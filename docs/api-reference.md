# Xoshiro512 Pseudo-Random Number Generator API

## Overview

The `Xoshiro512` class implements a pseudo-random number generator using the Xoshiro512** algorithm. This algorithm is designed for high-quality random number generation.

For more details about the Xoshiro512starstar algorithm, refer to [Xoshiro512starstar.c](https://prng.di.unimi.it/xoshiro512starstar.c).

## Class Members

### `Xoshiro512()`

- **Description:** Default constructor for the Xoshiro512 class.

### `Xoshiro512(uint64_t seed)`

- **Description:** Constructor for the Xoshiro512 class that allows initializing the generator with a seed.
- **Parameters:**
  - `seed`: The seed value to initialize the generator.

### `void setSeed(uint64_t seed)`

- **Description:** Method to set the seed of the generator.
- **Parameters:**
  - `seed`: The seed value to set.

### `uint64_t getUint64()`

- **Description:** Method to generate a random 64-bit unsigned integer uniformly distributed in the range 0 to `UINT64_MAX`.
- **Returns:** A random 64-bit unsigned integer.

### `uint64_t getUint64(const uint64_t &min, const uint64_t &max)`

- **Description:** Method to generate a random 64-bit unsigned integer within a specified range.
- **Parameters:**
  - `min`: The minimum bound of the range.
  - `max`: The maximum bound of the range.
- **Returns:** A random 64-bit unsigned integer within the specified range.

### `int64_t getInt64()`

- **Description:** Method to generate a random 64-bit signed integer uniformly distributed in the range `INT64_MIN` to `INT64_MAX`.
- **Returns:** A random 64-bit signed integer.

### `int64_t getInt64(const int64_t &min, const int64_t &max)`

- **Description:** Method to generate a random 64-bit signed integer within a specified range.
- **Parameters:**
  - `min`: The minimum bound of the range.
  - `max`: The maximum bound of the range.
- **Returns:** A random 64-bit signed integer within the specified range.

### `double getDouble()`

- **Description:** Method to generate a random uniform number in the range [0, 1).
- **Returns:** A random uniform number.

### `double getDouble(const double &min, const double &max)`

- **Description:** Method to generate a random uniform number within a specified range [min, max).
- **Parameters:**
  - `min`: The minimum value of the range.
  - `max`: The maximum value of the range.
- **Returns:** A random uniform number within the specified range.

### `double getGaussian(const double &mean = 0.0, const double &std_dev = 1.0)`

- **Description:** Method to generate a random number with a normal distribution with specified mean and standard deviation.
- **Parameters:**
  - `mean`: The mean value of the normal distribution (default: 0.0).
  - `std_dev`: The standard deviation of the normal distribution (default: 1.0).
- **Returns:** A random number with a normal distribution.

## Usage Example

```cpp
#include "Xoshiro512.hpp"

int main() {
    Xoshiro512 prng;

    // Generate a random 64-bit unsigned integer
    uint64_t randomUint = prng.getUint64();

    // Generate a random number with normal distribution
    double randomNormal = prng.getGaussian();

    return 0;
}