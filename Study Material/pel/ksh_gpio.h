// 모터 드라이버 제어를 위한 소스코드

#ifndef __KSH_GPIO_H__
#define __KSH_GPIO_H__

#include "stm32f4xx.h"

#define GPIO_MOTER_DRIVER_PORT        GPIOE
#define GPIO_MOTER_DRIVER_PERIPH      RCC_AHB1Periph_GPIOE

//PE1, PE2 (INA, INB)
#define GPIO_MOTER_DRIVER1_INA          GPIO_Pin_1
#define GPIO_MOTER_DRIVER1_INB          GPIO_Pin_2
//#define GPIO_MOTER_DRIVER2_INA          GPIO_Pin_3
//#define GPIO_MOTER_DRIVER2_INB          GPIO_Pin_4

// 모터 방향 설정을 위한 초기화 함수
void InitMoterDirConfig()
{
    GPIO_InitTypeDef GPIO_InitStructure;        //GPIO Setting (Structure about Pin, Mode, PuPd, OType, Speed, and so on)
    RCC_AHB1PeriphClockCmd(GPIO_MOTER_DRIVER_PERIPH, ENABLE);
    // Reset and Clock Control, ClockSetting 또는 Reset을 할 때 사용됨
    GPIO_InitStructure.GPIO_Pin = GPIO_MOTER_DRIVER1_INA | GPIO_MOTER_DRIVER1_INB;          // GPIO 사용할 핀 설정
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;       // GPIO Out 모드로 설정.
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;           // GPIO를 PullDown 모드로 설정
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;           // GPIO의 Output Type을 설정. PP는 Push Pull, OD는 Open-Drain
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;  // Speed를 설정. 100MHz 최대
    GPIO_Init(GPIO_MOTER_DRIVER_PORT, &GPIO_InitStructure);                      // A 포트의 GPIO 설정, GPIO_InitStructure와 같이 초기화
}

//****************** 모터 1******************

// 모터 1 Off
void moter1Off() {
  GPIO_MOTER_DRIVER_PORT->BSRRH = GPIO_MOTER_DRIVER1_INA;
  GPIO_MOTER_DRIVER_PORT->BSRRH = GPIO_MOTER_DRIVER1_INB;
}

// 모터1 정방향
void moter1Forward() {
  GPIO_MOTER_DRIVER_PORT->BSRRL = GPIO_MOTER_DRIVER1_INA;
  GPIO_MOTER_DRIVER_PORT->BSRRH = GPIO_MOTER_DRIVER1_INB;
}

// 모터1 역방향
void moter1Backward() {
  GPIO_MOTER_DRIVER_PORT->BSRRH = GPIO_MOTER_DRIVER1_INA;
  GPIO_MOTER_DRIVER_PORT->BSRRL = GPIO_MOTER_DRIVER1_INB;
}

//****************** 모터 2******************

//// 모터 2 Off
//void moter2Off() {
//  GPIO_MOTER_DRIVER_PORT->BSRRH = GPIO_MOTER_DRIVER2_INA;
//  GPIO_MOTER_DRIVER_PORT->BSRRH = GPIO_MOTER_DRIVER2_INB;
//}
//
//// 모터 2 정방향
//void moter2Forward() {
//  GPIO_MOTER_DRIVER_PORT->BSRRL = GPIO_MOTER_DRIVER2_INA;
//  GPIO_MOTER_DRIVER_PORT->BSRRH = GPIO_MOTER_DRIVER2_INB;
//}
//
//// 모터 2 역방향
//void moter2Backward() {
//  GPIO_MOTER_DRIVER_PORT->BSRRH = GPIO_MOTER_DRIVER2_INA;
//  GPIO_MOTER_DRIVER_PORT->BSRRL = GPIO_MOTER_DRIVER2_INB;
//}

#endif /*__KSH_GPIO_H__*/