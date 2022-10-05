/**
 * @file    main.cpp
 * @author  Mahima Arora
 * @version 1.0
 * @copyright GNU Public License
 * @brief Test-Driven Development for PID Controller
 * @section DESCRIPTION
 *  This file contains methods and attributes to support a PID controller
 * @dependencies: This file needs "pidController.hpp"
 */
// Included the required header files
#include <iostream>
#include "../include/pidController.hpp"
/**
 * @brief Function to initialize the controller constants 
          and call the compute functions which calculates the 
          final velocity.
 * 
 * @return int 
 */

// Parameters that are being passed:
// Kp = 0.5
// Ki = 1
// Kd = 0.01
// dt = 0.06
// process variable = 1
// Number of iterations = 200
int main() {
    PidController pidTest(0.5, 1, 0.01, 0.05, 1, 200);
    pidTest.computePidOutput();
    return 0;
}
