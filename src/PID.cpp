#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  //initailize the tuning parameters 
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_; 
  //set error to zero 
  p_error = 0;
  i_error = 0;
  d_error = 0; 
  
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  //derivative error is the change in error
  d_error = cte - p_error; 
  //proportional error is equal to the error reported by the simulator 
  p_error = cte; 
  //integrative error is the summation of all errors 
  i_error += cte; 
	
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  //sets the value that is returned 
  float total_error = -Kp*p_error - Kd*d_error - Ki*i_error; 
  //statements limit the max and min value that can be returned to assure steering is within limits  
  if (total_error > 1)
  {
    total_error = 1;
  }
  else if (total_error < -1)
  {
    total_error = -1; 
  }
  
  return total_error;  // TODO: Add your total error calc here!
}