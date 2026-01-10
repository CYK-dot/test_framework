#ifndef MATH_UTIL_H
#define MATH_UTIL_H

#include <stdexcept>

/**
 * @brief Adds two integers together
 */
int add(int a, int b);

/**
 * @brief Subtracts integer b from integer a
 */
int subtract(int a, int b);

/**
 * @brief Multiplies two integers
 */
int multiply(int a, int b);

/**
 * @brief Divides integer a by integer b
 * @throws std::invalid_argument if b is zero
 */
double divide(double a, double b);

/**
 * @brief Checks if a number is prime
 */
bool is_prime(int n);

#endif // MATH_UTIL_H