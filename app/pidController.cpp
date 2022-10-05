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
#include "../include/pidController.hpp"
#include <cmath>
#include <iostream>
// To-DO --> interations, max iterations ; min currentError value check

/**
 * @brief Constructer to initialize the class parameters
 * 
 * @param K_p 
 * @param K_i 
 * @param K_d 
 * @param d_t 
 * @param current_state 
 * @param target_state 
 */
PidController::PidController(double K_p, double K_i, double K_d,
double d_t, double current_state, double target_state) {
    Kp = K_p;
    Ki = K_i;
    Kd = K_d;
    dt = d_t;
    currentState = current_state;  // initial state
    targetState = target_state;    // final state
    currentError = 0;
    prevError = 0;
    integralSum = 0;
    checkParameters();
}

/**
 * @brief By getting the proportional, integral and derivative errors from their
          respective functions, the new process variable is calculated
 * 
 * @return double 
 */
double PidController::computePidOutput() {
    double pidOutput;
    int itr = 0;
    while (itr < 250) {
        currentError = targetState - currentState;
        pidOutput = proportionalController(currentError) +
        integralController(currentError) + derivativeContoller(currentError);
        prevError = currentError;
        currentState = pidOutput;
        itr++;
    }

    std::cout << "No. of Iterations : " << itr << std::endl;
    std::cout << "Target State : " << targetState << std::endl;
    std::cout << "Current State : " << currentState << std::endl;
    std::cout << std::endl;

    return pidOutput;
}
/**
 * @brief Function to calculate and return the Derivative error to compute function
 * 
 * @param error 
 * @return double 
 */
// returns derivative error
double PidController::derivativeContoller(double error) {
    double derError = Kd * std::abs((prevError - error) / dt);
    return derError;
}
/**
 * @brief Function to calculate and return the Integral error to compute functions
 * 
 * @param error 
 * @return double 
 */
double PidController::integralController(double error) {
    integralSum += error;  // cumulative error
    double intError = Ki * integralSum * dt;
    return intError;
}
/**
 * @brief Function to calculate and return the Proportional error to compute function
 * 
 * @param error 
 * @return double 
 */
// returns proportional error
double PidController::proportionalController(double error) {
    double propError = Kp * error;
    return propError;
}
/**
 * @brief Function that checks if all parameters are positive
 * 
 * @return true 
 * @return false 
 */
bool PidController::checkParameters() {
    if (dt <= 0 || Kp <= 0 || Ki <= 0 || Kd <= 0) {
        std::cout << "ERROR: parameters cannot be zero or negative.";
        std::cout << "Check again." << std::endl;
        return false;
    }
    if (targetState < currentState) {
        std::cout << "ERROR: Current State is greater than ";
        std::cout << "Target State." << std::endl;
        return false;
    }
    return true;  // returns true if all parameters are present and positive
}
