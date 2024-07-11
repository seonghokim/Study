// Interaction Lab.

// Jaeu's M4 Library
//      ��Ƽ�� ��� ���� ���̺귯�� �����Դϴ�.

#ifndef __KSH_PELTIER_CONTROL_H__
#define __KSH_PELTIER_CONTROL_H__

// ��Ƽ�� ��Ʈ���ϱ� ���� ���̺귯���� �ҷ��ɴϴ�.
//#include "jj_usart.h"
//#include "jj_pwm.h"     // <-- included jj_timer.h
#include "ksh_gpio.h"
#include "ksh_pid.h"
#include "ksh_adc.h"

// �µ� ������ ���� ��ũ�� ����Դϴ�.
#define DEFAULT_ADC_MAX 4095
#define DEFAULT_B       3454
#define DEFAULT_TO      37.0
#define DEFAULT_RO      14015  // Killo Ohm!!!!
#define DEFAULT_R2      14015   // Killo Ohm!!!!, 11.75 , 14.220

#define TIME_SCALER     0x8C

// ��Ƽ�� ��� ���� �Ķ���� �����Դϴ�.
typedef struct _pelCtrlVal {
    PidData      pidData;
    double      targetTemp;
    int             cntTime;
    char          toggleReachedTargetTemp;
    char          cmdPeltier;
} PelCtrlVal;

// Prototype of functions
void initPeltierControl();
double calR1(int adcMax, int adcVal, double R2);
double calR2(int adcMax, int adcVal, double R1);
char isReachedTargetTemp(double targetTemp, double currentTemp, double error);
double calTempFromThermistor(int adcMax, int adcVal, 
                             int To, double Ro, int B, double R1, double R2);

void initPelCtrlVal(PelCtrlVal* pelVal, double pVal, double iVal, double dVal);
void setPelCtrlVal(PelCtrlVal* pelVal, double _targetTemp, char _cmdPeltier);

// ���� �Լ� ����

// Initalize Setting to Control Peltier
void initPeltierControl() {
  InitMoterDirConfig();
  Init_ADC();           // <-- �µ� �� ���� ������ ���� ADC �����Դϴ�.
}

double calR1(int adcMax, int adcVal, double R2) {
  double resistor = (double)adcMax / adcVal - 1;
  return R2 * resistor;
}

double calR2(int adcMax, int adcVal, double R1) {
  double resistor = (double)adcMax / adcVal - 1;
  return R1 / resistor;
}

char isReachedTargetTemp(double targetTemp, double currentTemp, double error) {
    if((currentTemp < targetTemp + error)&& (currentTemp > targetTemp - error)) {
      return 1;
    }
   else {
      return 0;
   }
}
double calTempFromThermistor(int adcMax, int adcVal, 
                             int To, double Ro, int B, double R1, double R2)
{
  double resistor;
  double steinhart;
  
  if(R1 < 0.0) {
    resistor = calR1(adcMax, adcVal, R2);
  }
  else if(R2 < 0.0) {
    resistor = calR2(adcMax, adcVal, R1);
  }
  else return -1;
  
  // 1/T = 1/To + 1/B * ln(R/Ro)
  steinhart = resistor / Ro;
  steinhart = log(steinhart);
  steinhart /= (double)B;
  steinhart += 1.0 / (To + 273.15);
  steinhart = 1.0 / steinhart;
  steinhart -= 273.15;
  
  return steinhart;
}

void initPelCtrlVal(PelCtrlVal* pelVal, double pVal, double iVal, double dVal) {
  InitPID(&(pelVal->pidData), pVal, iVal, dVal);
  pelVal->targetTemp = 25.0;
  pelVal->cntTime = 0;
  pelVal->toggleReachedTargetTemp = 0;
  pelVal->cmdPeltier = 'q';
}

void setPelCtrlVal(PelCtrlVal* pelVal, double _targetTemp, char _cmdPeltier) {
  pelVal->targetTemp = _targetTemp;
  pelVal->cntTime = 0;
  pelVal->toggleReachedTargetTemp = 0;
  pelVal->cmdPeltier = _cmdPeltier;
}

#endif /*__KSH_PELTIER_CONTROL_H__*/