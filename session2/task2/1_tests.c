/**
 * @file 1_tests.c
 * @brief Unit testing with Acutest - test the is_palindrome() function
 *
 * COMP1850 Week 6 Session 2 - Task 2
 *
 * Write test functions using Acutest to verify is_palindrome() works correctly.
 * An example test is provided - add more tests covering different cases.
 */

#include "acutest.h"
#include <string.h>
#include <ctype.h>

#define BAD_STRING -1

/* Function prototype */
int is_palindrome(const char *str);

/* ============================================================
 * EXAMPLE TEST - Students should follow this pattern
 * ============================================================ */

void test_obvious_palindrome(void) {
    TEST_CHECK(is_palindrome("racecar") == 1);
    TEST_MSG("Expected 'racecar' to be a palindrome");
}

/* ============================================================
 * TODO: Add your test functions below
 *
 * Consider testing:
 * - Single characters: "a"
 * - Empty string: ""
 * - Non-palindromes: "hello", "world"
 * - Even-length palindromes: "abba", "deed"
 * - Edge cases: case sensitivity, spaces
 *
 * Each test function should:
 * 1. Call TEST_CHECK(condition) to verify a condition
 * 2. Use TEST_MSG("message") to explain what went wrong if it fails
 * ============================================================ */

void test_empty_string(void) {
    TEST_CHECK(is_palindrome("") == BAD_STRING);
    TEST_MSG("Expected BAD STRING error");
}

void test_single_char(void) {
    TEST_CHECK(is_palindrome("A") == 1);
    TEST_MSG("Expected 'A' is palindrome ");
}

void test_non_palindrome(void)
{
    TEST_CHECK(is_palindrome("tomato") == 0);
    TEST_MSG("Expected 'tomato' is not palindrome");
}

void test_even_letter_palindrome(void)
{
    TEST_CHECK(is_palindrome("adda")==1);
    TEST_MSG("Expected adda is palindrome");
}

void test_mixed_case(void)
{
    TEST_CHECK(is_palindrome("Racecar")==1);
    TEST_MSG("Expected Racecar is palindrome");
}

/* ============================================================
 * TEST_LIST - Register all your tests here
 *
 * Format: { "test name shown in output", function_name },
 * Must end with { NULL, NULL }
 * ============================================================ */
TEST_LIST = {
    { "obvious palindrome (racecar)", test_obvious_palindrome },
    /* TODO: Add your tests here, e.g.:
     * { "single character", test_single_char },
     * { "empty string", test_empty_string },
     */
    { "bad string (empty)", test_empty_string },
    { "single character palindrome", test_single_char },
    { "non-palindrome", test_non_palindrome },
    {"even number of letters", test_even_letter_palindrome},
    { "non-matching case", test_mixed_case },
    { NULL, NULL }
};

/* ============================================================
 * IMPLEMENTATION - Do not modify
 * ============================================================ */

/**
 * @brief Checks if a given string is a palindrome.
 *
 * @param str The string to be checked.
 * @return int 1 if the string is a palindrome, 0 otherwise.
 */
int is_palindrome(const char *str) {
    int len = strlen(str);
    if (len==0) return BAD_STRING;

    for (int i = 0; i < len / 2; i++) {
        if (toupper(str[i]) != toupper(str[len - i - 1])) {
            return 0;
        }
    }
    return 1;
}
