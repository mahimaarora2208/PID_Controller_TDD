
/**
 *  @file    test.cpp
 *  @author  Mahima Arora
 *  @version 2.0
 *  @copyright GNU Public License
 *
 *  @brief Rest-Driven Development of PID PIDController
 *
 *  @section DESCRIPTION
 *
 *  This is test file to declare the test cases for the PID controller
 *
*/


#include <gtest/gtest.h>
#include <memory>
#include "lib.hpp"

std::shared_ptr<PIDController>
    PID_Controller;  ///< Shared pointer for PIDController class as PID_Controller

/**
 * @brief Class initialization test
 */
TEST(PIDTests, initializationTest) {
  PID_Controller = std::make_shared<PIDController>();

  // EXPECT_TRUE(PID_Controller->isInitialized());
}

/**
 * @brief Class's get and set function test
 */
TEST(PIDTests, valuesTest) {
  PID_Controller = std::make_shared<PIDController>(0.3, 0.05, 0.1);

  EXPECT_NEAR(PID_Controller->getkP(), 0.3, 0.001);
  EXPECT_NEAR(PID_Controller->getkI(), 0.05, 0.001);
  EXPECT_NEAR(PID_Controller->getkD(), 0.1, 0.001);
}

/**
 * @brief Test the convergence of logic
 */
TEST(PIDTests, computeTest) {
  PID_Controller = std::make_shared<PIDController>(0.3, 0.05, 0.1);

  PID_Controller->computeVelocity(10.0, 0.0);

  EXPECT_NEAR(PID_Controller->returnState(), 13.5, 0.001);
}

TEST(PIDTests, setCasesTest) {
  PID_Controller = std::make_shared<PIDController>();

  PID_Controller->setkP(0.3);
  PID_Controller->setkI(1.5);
  PID_Controller->setkD(0.06);

  EXPECT_EQ(PID_Controller->getkP(), 0.3);
  EXPECT_EQ(PID_Controller->getkI(), 1.5);
  EXPECT_EQ(PID_Controller->getkD(), 0.06);
}