#include <gtest/gtest.h>
#include "math_util.h"

// Test for addition function
TEST(MathUtilTest, AdditionTest) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(-1, 1), 0);
    EXPECT_EQ(add(0, 0), 0);
    EXPECT_EQ(add(-5, -3), -8);
}

// Test for subtraction function
TEST(MathUtilTest, SubtractionTest) {
    EXPECT_EQ(subtract(5, 3), 2);
    EXPECT_EQ(subtract(0, 5), -5);
    EXPECT_EQ(subtract(-2, -3), 1);
    EXPECT_EQ(subtract(10, 10), 0);
}

// Test for multiplication function
TEST(MathUtilTest, MultiplicationTest) {
    EXPECT_EQ(multiply(3, 4), 12);
    EXPECT_EQ(multiply(-2, 3), -6);
    EXPECT_EQ(multiply(0, 100), 0);
    EXPECT_EQ(multiply(-4, -5), 20);
}

// Test for division function
TEST(MathUtilTest, DivisionTest) {
    EXPECT_DOUBLE_EQ(divide(10, 2), 5.0);
    EXPECT_DOUBLE_EQ(divide(7, 2), 3.5);
    EXPECT_NEAR(divide(1, 3), 0.333333, 1e-6);
    
    // Test division by zero exception
    EXPECT_THROW(divide(5, 0), std::invalid_argument);
}

// Test for prime number function
TEST(MathUtilTest, PrimeTest) {
    EXPECT_TRUE(is_prime(2));
    EXPECT_TRUE(is_prime(3));
    EXPECT_TRUE(is_prime(5));
    EXPECT_TRUE(is_prime(7));
    EXPECT_TRUE(is_prime(11));
    EXPECT_TRUE(is_prime(13));
    
    EXPECT_FALSE(is_prime(1));
    EXPECT_FALSE(is_prime(4));
    EXPECT_FALSE(is_prime(6));
    EXPECT_FALSE(is_prime(8));
    EXPECT_FALSE(is_prime(9));
    EXPECT_FALSE(is_prime(10));
}

// Main function to run tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}