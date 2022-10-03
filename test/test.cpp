/**
 * @file test.cpp
 * @author Mahima Arora (marora1@umd.edu)
 * @brief .hpp file for PID controller
 * @version 0.1
 * @date 2022-10-02
 * @section Class Description
 *
 * Header file for PID Controller
 *
 */
#include <gtest/gtest.h>
#include <../include/pidController.hpp>


TEST(PidTests, test_computePidOutput) {
    PidController PidController(0.1, 0.2, 0.1, 0.005);
    double result = PidController.computePidOutput(0.1, 0.2, 0.1);
    ASSERT_EQ(result, 7);
    // use ASSERT_NEAR for PID controller for real values
}

TEST(checkAllParameters, test_checkParameters) {
    PidController PidController(0.1, 0.2, 0.1, 0.005);
    bool result = PidController.checkParameters();
    ASSERT_TRUE(result); // returns true if all parameters are present
    // use ASSERT_NEAR for PID controller for real values
}