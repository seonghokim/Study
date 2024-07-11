#ifndef __KSH_ADC_H__
#define __KSH_ADC_H__

#include "stm32f4xx.h"
#include <math.h>

#define ADC_APB_PERIPH                  RCC_APB2Periph_ADC1

#define GPIO_ADC_AHB_PERIPH1            RCC_AHB1Periph_GPIOC


#define GPIO_ADC_PORT1                  GPIOC
#define GPIO_ADC_PORT2                  GPIOA

//PC0, PC2
#define GPIO_PELTIER1_TEMP_PIN          GPIO_Pin_0     // GPIO_ADC_PORT1
#define GPIO_PELTIER2_TEMP_PIN          GPIO_Pin_2     // GPIO_ADC_PORT1
#define GPIO_PELTIER1_TEMP_ADC_CN       ADC_Channel_10
#define GPIO_MOTER1_CS_ADC_CN           ADC_Channel_13


void Init_ADC();
uint16_t ADC_Read(ADC_TypeDef* ADCx, uint8_t channel);

void Init_ADC(){
    GPIO_InitTypeDef GPIO_InitStructure;
    ADC_InitTypeDef ADC_InitStructure;
    ADC_CommonInitTypeDef ADC_CommonInitStructure;

    /* Enable ADC1 and GPIOC clock */
    RCC_APB2PeriphClockCmd(ADC_APB_PERIPH, ENABLE);
    RCC_AHB1PeriphClockCmd(GPIO_ADC_AHB_PERIPH1, ENABLE);


    /* ADC Common Init */
    ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
    ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div4;     // ADC clock = PCLK2/prescaler. ADC freq = typical 30MHz, Max 36MHz. PCLK2 = 168/2=84MHz.
    ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
    ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;
    ADC_CommonInit(&ADC_CommonInitStructure);

    /* ADC channel 10, 12, 13 (PC0, PC2) configuration */
    GPIO_InitStructure.GPIO_Pin = GPIO_PELTIER1_TEMP_PIN | GPIO_PELTIER2_TEMP_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIO_ADC_PORT1, &GPIO_InitStructure);

    /* ADC channel configuration */
    ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;
    ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
    ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T1_CC1;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_NbrOfConversion = 1;
    ADC_Init(ADC1, &ADC_InitStructure);

    /* ADC1 regular channels configuration */
    ADC_RegularChannelConfig(ADC1, GPIO_PELTIER1_TEMP_ADC_CN, 1, ADC_SampleTime_3Cycles);
    ADC_RegularChannelConfig(ADC1, GPIO_MOTER1_CS_ADC_CN, 1, ADC_SampleTime_3Cycles);

    /* Enable ADC1 */ 
    ADC_Cmd(ADC1, ENABLE);
}

uint16_t ADC_Read(ADC_TypeDef* ADCx, uint8_t channel) {
	uint32_t timeout = 0xFFF;
	
	ADC_RegularChannelConfig(ADCx, channel, 1, ADC_SampleTime_15Cycles);

	/* Start software conversion */
	ADCx->CR2 |= (uint32_t)ADC_CR2_SWSTART;
	
	/* Wait till done */
	while (!(ADCx->SR & ADC_SR_EOC)) {
		if (timeout-- == 0x00) {
			return 0;
		}
	}
	
	/* Return result */
	return ADCx->DR;
}

uint16_t readPeltier1TempADCVal(void) {
  return ADC_Read(ADC1, GPIO_PELTIER1_TEMP_ADC_CN);
}


uint16_t readMoter1CSADCVal(void) {
  return ADC_Read(ADC1, GPIO_MOTER1_CS_ADC_CN);
}


#endif /*__KSH_ADC_H__*/