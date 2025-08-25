#ifndef UNITY_FRAMEWORK_H
#define UNITY_FRAMEWORK_H

#include <stdio.h>
#include <stdlib.h>

/* Test result counters */
extern int Unity_TestsPassed;
extern int Unity_TestsFailed;

/* Test assertions */
#define TEST_ASSERT_TRUE(condition) \
    do { \
        if (condition) { \
            Unity_TestsPassed++; \
        } else { \
            Unity_TestsFailed++; \
            printf("FAIL: %s:%d - Expected true, got false\n", __FILE__, __LINE__); \
        } \
    } while(0)

#define TEST_ASSERT_FALSE(condition) \
    do { \
        if (!(condition)) { \
            Unity_TestsPassed++; \
        } else { \
            Unity_TestsFailed++; \
            printf("FAIL: %s:%d - Expected false, got true\n", __FILE__, __LINE__); \
        } \
    } while(0)

#define TEST_ASSERT_EQUAL_INT(expected, actual) \
    do { \
        if ((expected) == (actual)) { \
            Unity_TestsPassed++; \
        } else { \
            Unity_TestsFailed++; \
            printf("FAIL: %s:%d - Expected %d, got %d\n", __FILE__, __LINE__, (expected), (actual)); \
        } \
    } while(0)

#define TEST_ASSERT_EQUAL_STRING(expected, actual) \
    do { \
        if (strcmp((expected), (actual)) == 0) { \
            Unity_TestsPassed++; \
        } else { \
            Unity_TestsFailed++; \
            printf("FAIL: %s:%d - Expected \"%s\", got \"%s\"\n", __FILE__, __LINE__, (expected), (actual)); \
        } \
    } while(0)

/* Test runner macros */
#define RUN_TEST(test_func) \
    do { \
        printf("Running " #test_func "... "); \
        test_func(); \
        printf("PASS\n"); \
    } while(0)

#define UNITY_BEGIN() \
    do { \
        Unity_TestsPassed = 0; \
        Unity_TestsFailed = 0; \
        printf("Starting test run...\n"); \
    } while(0)

#define UNITY_END() \
    do { \
        printf("\nTest Results:\n"); \
        printf("Passed: %d\n", Unity_TestsPassed); \
        printf("Failed: %d\n", Unity_TestsFailed); \
        printf("Total: %d\n", Unity_TestsPassed + Unity_TestsFailed); \
        return Unity_TestsFailed; \
    } while(0)

#endif /* UNITY_FRAMEWORK_H */