// Program for PWM timers
#include "stm32f4_discovery.h"
#include "stm32f4xx_conf.h" // again, added because ST didn't put it here ?
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_tim.h"

#define DELAY_PERIOD 0x4FFFF


void Delay(__IO uint32_t nCount)
{
  while(nCount--)
  {
  }
}
void TimerInitialization() {
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
  TIM_TimeBaseInitTypeDef defstruct;
  defstruct.TIM_Prescaler = 10;
  defstruct.TIM_CounterMode = TIM_CounterMode_Up;
  defstruct.TIM_Period = 8399;
  defstruct.TIM_ClockDivision = TIM_CKD_DIV1;
  defstruct.TIM_RepetitionCounter = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM4, &defstruct);
  TIM_Cmd(TIM4, ENABLE);
}


void PWMInitialization()
{
    TIM_OCInitTypeDef output;
    output.TIM_OCMode = TIM_OCMode_PWM1;
    output.TIM_Pulse = 2099;
    output.TIM_OutputState = TIM_OutputState_Enable;
    output.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OC1Init(TIM4, &output);
    TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);
}


int main () {
    TimerInitialization();
    PWMInitialization();

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_TIM4);

    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_Init(GPIOD, &GPIO_InitStruct);


    while (1) {
        int i;
        for (i = 0; i <= 8399; i+=5) {
            TIM4->CCR1 = i;
            Delay(DELAY_PERIOD);
        }

    }
}
