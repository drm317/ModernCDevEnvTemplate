#include "unity/unity.h"
#include "math_utils.h"
#include <string.h>

void test_add_numbers_positive(void) {
    TEST_ASSERT_EQUAL_INT(5, add_numbers(2, 3));
    TEST_ASSERT_EQUAL_INT(10, add_numbers(4, 6));
}

void test_add_numbers_negative(void) {
    TEST_ASSERT_EQUAL_INT(-5, add_numbers(-2, -3));
    TEST_ASSERT_EQUAL_INT(1, add_numbers(-2, 3));
}

void test_multiply_numbers(void) {
    TEST_ASSERT_EQUAL_INT(6, multiply_numbers(2, 3));
    TEST_ASSERT_EQUAL_INT(0, multiply_numbers(0, 5));
    TEST_ASSERT_EQUAL_INT(-10, multiply_numbers(-2, 5));
}

void test_is_even(void) {
    TEST_ASSERT_TRUE(is_even(2));
    TEST_ASSERT_TRUE(is_even(0));
    TEST_ASSERT_TRUE(is_even(-4));
    TEST_ASSERT_FALSE(is_even(1));
    TEST_ASSERT_FALSE(is_even(-3));
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_add_numbers_positive);
    RUN_TEST(test_add_numbers_negative);
    RUN_TEST(test_multiply_numbers);
    RUN_TEST(test_is_even);

    UNITY_END();
}