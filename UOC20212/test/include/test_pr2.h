#ifndef __TEST_PR2_H__
#define __TEST_PR2_H__

#include <stdbool.h>
#include "test_suite.h"

// Run all tests for PR2
bool run_pr2(tTestSuite* test_suite, const char* input);

// Run tests for PR2 exercice 1
bool run_pr2_ex1(tTestSection* test_section, const char* input);

// Run tests for PR2 exercice 2
bool run_pr2_ex2(tTestSection* test_section, const char* input);

// Run tests for PR2 exercice 3
bool run_pr2_ex3(tTestSection* test_section, const char* input);


#endif // __TEST_PR2_H__