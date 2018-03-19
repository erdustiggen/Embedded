// Program for PWM timers
#include "stm32f4_discovery.h"
#include "stm32f4xx_conf.h" // again, added because ST didn't put it here ?
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_tim.h"
#include "defines.h"
#include <stdlib.h>

void TimerInitialization() {
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
  TIM_TimeBaseInitTypeDef defstruct;
  defstruct.TIM_Prescaler = 40000;
  defstruct.TIM_CounterMode = TIM_CounterMode_Up;
  defstruct.TIM_Period = 500;
  defstruct.TIM_ClockDivision = TIM_CKD_DIV1;
  defstruct.TIM_RepetitionCounter = 0;
  TIM_TimeBaseInit(TIM4, &defstruct);
  TIM_Cmd(TIM4, ENABLE);
}


void PWMInitialization()
{
    TIM_OCInitTypeDef output = {0,};
    output.TIM_OCMode = TIM_OCMode_PWM1;
    output.TIM_Pulse = 400;
    output.TIM_OutputState = TIM_OutputState_Enable;
    output.TIM_OCPolarity = TIM_OCPolarity_High;

    TIM_OC1Init(TIM4, &output);
    TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);

    GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_TIM4);
}

void LEDinitialization()
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
    GPIO_InitTypeDef gpiostruct;
    gpiostruct.GPIO_Pin = GPIO_Pin_12;
    gpiostruct.GPIO_Mode = GPIO_Mode_AF;
    gpiostruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &gpiostruct);
}

int main () {
  while (1) {
    LEDinitialization();
    TimerInitialization();
    PWMInitialization();
  }
}
