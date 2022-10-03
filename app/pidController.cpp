/**
 * @file    PIDController.cpp
 * @author  Mahima Arora
 * @version 2.0
 * @copyright GNU Public License
 * @brief Test-Driven Development for PID Controller
 * @section DESCRIPTION
 *  This file contains methods and attributes to support a PID controller
 * @dependencies: This file needs "pidController.hpp"
 */

#include <iostream>
#include "pidController.hpp"

PidController::PidController(double K_p, double K_i, double K_d, double d_t) {
    Kp = K_p;
    Ki = K_i;
    Kd = K_d;
    dt = d_t;
}

double PidController::computePidOutput(double Kp, double Ki, double Kd) {
    std::cout << "Inside computeVelcity Class Member!" << std::endl;
    return 0;
}

double PidController::derivativeContoller(double Kd) {
    // returns derivative error
    return 0;
};

double PidController::integralController(double Ki) {
    // returns integral error
    return 0;
};
double PidController::proportionalController(double Kp) {
    // returns proportional error
    return 0;
};
int main() {
    std::cout << "stupid program!!!!";
}
