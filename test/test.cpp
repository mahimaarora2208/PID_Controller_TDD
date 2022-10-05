/**
 * @file test.cpp
 * @author Mahima Arora (marora1@umd.edu)
 * @brief .hpp file for PID controller
 * @version 0.1
 * @copyright GNU Public License
 * @date 2022-10-02
 * @section Class Description
 *
 * Header file for PID Controller
 *
 */

// Included the required header files
#include <gtest/gtest.h>
#include "../include/pidController.hpp"

/**
 * @brief Unit test to check the compute function 
          if the final value is comparable to the
          set point
 * 
 */
TEST(PidTests, test_computePidOutput) {
    // PASS
    PidController pidTest(0.5, 1, 0.01, 0.05, 1, 5);
    double result = pidTest.computePidOutput();
    ASSERT_NEAR(result, 5, 0.5);
    // use ASSERT_NEAR for PID controller for real values
}

/**
 * @brief Unit test to check if all the parameters are 
          passed to the compute function and also to 
          check if the passed paramters are positive
 * 
 */

TEST(checkAllParameters, test_checkParameters) {
    // PASS
    PidController pidTest(0.5, 1, 0.01, 0.05, 1, 5);
    bool result = pidTest.checkParameters();
    ASSERT_TRUE(result);  // returns true if all parameters are present
    // use ASSERT_NEAR for PID controller for real values
}

/**
 * @brief Unit test to check if all the parameters are 
          passed to the compute function and also to 
          check if the passed paramters are positive
 * 
 */

TEST(checkAllParameters1, test_checkParameters) {
    // PASS
    PidController pidTest(-0.5, 1, 0.01, 0.05, 1, 5);
    bool result = pidTest.checkParameters();
    ASSERT_FALSE(result);  // returns true if all parameters are present
    // use ASSERT_NEAR for PID controller for real values
}

/**
 * @brief Unit test to check if all the parameters are 
          passed to the compute function and also to 
          check if the passed paramters are positive
 * 
 */
TEST(checkAllParameters2, test_checkParameters) {
    PidController pidTest(0.5, 1, 0.01, 0.05, 15, 5);
    bool result = pidTest.checkParameters();
    ASSERT_FALSE(result);  // returns true if all parameters are present
    // use ASSERT_NEAR for PID controller for real values
}
