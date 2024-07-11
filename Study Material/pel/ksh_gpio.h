// ���� ����̹� ��� ���� �ҽ��ڵ�

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

// ���� ���� ������ ���� �ʱ�ȭ �Լ�
void InitMoterDirConfig()
{
    GPIO_InitTypeDef GPIO_InitStructure;        //GPIO Setting (Structure about Pin, Mode, PuPd, OType, Speed, and so on)
    RCC_AHB1PeriphClockCmd(GPIO_MOTER_DRIVER_PERIPH, ENABLE);
    // Reset and Clock Control, ClockSetting �Ǵ� Reset�� �� �� ����
    GPIO_InitStructure.GPIO_Pin = GPIO_MOTER_DRIVER1_INA | GPIO_MOTER_DRIVER1_INB;          // GPIO ����� �� ����
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;       // GPIO Out ���� ����.
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;           // GPIO�� PullDown ���� ����
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;           // GPIO�� Output Type�� ����. PP�� Push Pull, OD�� Open-Drain
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;  // Speed�� ����. 100MHz �ִ�
    GPIO_Init(GPIO_MOTER_DRIVER_PORT, &GPIO_InitStructure);                      // A ��Ʈ�� GPIO ����, GPIO_InitStructure�� ���� �ʱ�ȭ
}

//****************** ���� 1******************

// ���� 1 Off
void moter1Off() {
  GPIO_MOTER_DRIVER_PORT->BSRRH = GPIO_MOTER_DRIVER1_INA;
  GPIO_MOTER_DRIVER_PORT->BSRRH = GPIO_MOTER_DRIVER1_INB;
}

// ����1 ������
void moter1Forward() {
  GPIO_MOTER_DRIVER_PORT->BSRRL = GPIO_MOTER_DRIVER1_INA;
  GPIO_MOTER_DRIVER_PORT->BSRRH = GPIO_MOTER_DRIVER1_INB;
}

// ����1 ������
void moter1Backward() {
  GPIO_MOTER_DRIVER_PORT->BSRRH = GPIO_MOTER_DRIVER1_INA;
  GPIO_MOTER_DRIVER_PORT->BSRRL = GPIO_MOTER_DRIVER1_INB;
}

//****************** ���� 2******************

//// ���� 2 Off
//void moter2Off() {
//  GPIO_MOTER_DRIVER_PORT->BSRRH = GPIO_MOTER_DRIVER2_INA;
//  GPIO_MOTER_DRIVER_PORT->BSRRH = GPIO_MOTER_DRIVER2_INB;
//}
//
//// ���� 2 ������
//void moter2Forward() {
//  GPIO_MOTER_DRIVER_PORT->BSRRL = GPIO_MOTER_DRIVER2_INA;
//  GPIO_MOTER_DRIVER_PORT->BSRRH = GPIO_MOTER_DRIVER2_INB;
//}
//
//// ���� 2 ������
//void moter2Backward() {
//  GPIO_MOTER_DRIVER_PORT->BSRRH = GPIO_MOTER_DRIVER2_INA;
//  GPIO_MOTER_DRIVER_PORT->BSRRL = GPIO_MOTER_DRIVER2_INB;
//}

#endif /*__KSH_GPIO_H__*/