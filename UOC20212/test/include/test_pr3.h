#ifndef __TEST_PR3_H__
#define __TEST_PR3_H__

#include <stdbool.h>
#include "test_suite.h"

// Run all tests for PR3
bool run_pr3(tTestSuite* test_suite, const char* input);

// Run tests for PR3 exercice 1
bool run_pr3_ex1(tTestSection* test_section, const char* input);

// Run tests for PR3 exercice 2
bool run_pr3_ex2(tTestSection* test_section, const char* input);

// Run tests for PR3 exercice 3
bool run_pr3_ex3(tTestSection* test_section, const char* input);


#endif // __TEST_PR3_H__