/*
  Author : Jaeu Jeong (wodndb@koreatech.ac.kr)
  Ref : http://robotsforroboticists.com/pid-control/
*/

#ifndef __KSH_PID_H__
#define __KSH_PID_H__

#include <stdio.h>

typedef struct _PID_DATA {
  // Accumulated data for PID control
  double preError;
  double integral;
  
  // PID control parameter
  double Kp;
  double Ki;
  double Kd;
} PidData;

void InitPID(PidData* pidData, double pVal, double iVal, double dVal) {
  pidData->preError = 0;
  pidData->integral = 0;

  // Set PID Parameter
  pidData->Kp = pVal;
  pidData->Ki = iVal;
  pidData->Kd = dVal;
}

double PID_control(double targetVal, double actVal, int ctrlFreq, PidData* pidData, int bias) {
  double error = 0;
  double derivative = 0;
  double output = 0;
  
  error = targetVal - actVal;
  pidData->integral = pidData->integral + ((double)error / (double)ctrlFreq);
  
  // Limit integral value
  // [Comment] I customize this code area for avoiding too accumulated integral value.
  if(pidData->integral < -60) {
    pidData->integral = -60;
  }
  if(pidData->integral > 60) {
    pidData->integral = 60;
  }
  
  derivative = (error - pidData->preError) * ctrlFreq;
  
  output = (pidData->Kp) * error + 
           (pidData->Ki) * (pidData->integral) +
           (pidData->Kd) * (derivative) + 
           0;   //bias
  
  pidData->preError = error;
  
  return output;
}

double PI_control(double targetVal, double actVal, int ctrlFreq, PidData* pidData) {
  double error = 0;
  double output = 0;
  
  error = targetVal - actVal;
  pidData->integral = pidData->integral + ((double)error / (double)ctrlFreq);
  
  output = (pidData->Kp) * error + 
           (pidData->Ki) * (pidData->integral);
  
  pidData->preError = error;
  
  return output;
}

double P_control(double targetVal, double actVal, int ctrlFreq, PidData* pidData) {
  double error = 0;
  double output = 0;
  
  error = targetVal - actVal;
  
  pidData->integral = pidData->integral + ((double)error / (double)ctrlFreq);
  output = (pidData->Kp) * error;
  
  pidData->preError = error;
  
  return output;
}

#endif /*__KSH_PID_H__*/