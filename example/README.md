# Example Project - Math Utility Library

This example demonstrates how to use the CMake Google Test Framework to create and run unit tests with code coverage reporting.

## Project Structure

- `CMakeLists.txt`: CMake configuration for the example project
- `product/math_util.h`: Header file defining math utility functions
- `product/math_util.cpp`: Implementation of math utility functions
- `testcase/testcase.cpp`: Google Test unit tests for the math utility functions

## Math Utility Functions

The example library provides the following functions:

- `add(a, b)`: Returns the sum of two integers
- `subtract(a, b)`: Returns the difference of two integers
- `multiply(a, b)`: Returns the product of two integers
- `divide(a, b)`: Returns the quotient of two doubles (throws exception if dividing by zero)
- `is_prime(n)`: Checks if a number is prime

## Building and Running Tests

### Prerequisites

- CMake 3.14 or higher
- A C++ compiler supporting C++14 or later
- gcovr (for coverage reports, optional)

### Build Instructions

```bash
mkdir build
cd build
cmake ..
make
```

### Run Tests

```bash
# Run all tests
./math_util_test

# Run tests and generate coverage reports
make cov
```

### Coverage Reports

After running `make cov`, coverage reports will be generated in the `build/coverage/` directory:
- `coverage.xml`: XML format for CI systems
- `coverage.html`: Human-readable HTML report
- `coverage.txt`: Text summary

## CMake Configuration

The example demonstrates the usage of the following functions from the test framework:

- `enable_test_framework()`: Sets up Google Test integration
- `enable_code_coverage()`: Enables code coverage instrumentation
- `add_test_executable()`: Creates the test executable with proper linking
- `add_coverage_target()`: Sets up coverage reporting target

## Test Cases

The test suite covers various scenarios for each math function:
- Normal operation cases
- Edge cases
- Error conditions (like division by zero)
- Boundary conditions for prime number detection