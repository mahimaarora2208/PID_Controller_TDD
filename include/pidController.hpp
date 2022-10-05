/**
 * @file pidController.hpp
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

#ifndef DESKTOP_GIT_PID_CONTROLLER_TDD_INCLUDE_PIDCONTROLLER_HPP_
#define DESKTOP_GIT_PID_CONTROLLER_TDD_INCLUDE_PIDCONTROLLER_HPP_

/**
 *  @brief Class that implements PID Controller
 */
class PidController {
 private:
  double Kp;            // Proportional Gain
  double Ki;            // Integral Gain
  double Kd;            // Differential Gain
  double dt;            // time difference
  double currentState;  // initial state
  double targetState;   // final state
  double currentError;
  double prevError;
  double integralSum;

 public:
  PidController(double, double, double, double, double, double);
  double derivativeContoller(double);
  double integralController(double);
  double proportionalController(double);
  double computePidOutput();
  bool checkParameters();
};
#endif  // DESKTOP_GIT_PID_CONTROLLER_TDD_INCLUDE_PIDCONTROLLER_HPP_
