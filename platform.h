
#ifndef PLATFORM_H
#define PLATFORM_H

#include <stdint.h>

#define DEMCR       (*(volatile uint32_t*)0xE000EDFC)
#define DWT_CTRL    (*(volatile uint32_t*)0xE0001000)
#define DWT_CYCCNT  (*(volatile uint32_t*)0xE0001004)

#define SYST_CSR (*(volatile uint32_t*)0xE000E010)
#define SYST_RVR (*(volatile uint32_t*)0xE000E014)
#define SYST_CVR (*(volatile uint32_t*)0xE000E018)

#define RCC_AHB1ENR (*(volatile uint32_t*)0x40023830)
#define GPIOB_MODER (*(volatile uint32_t*)0x40020400)
#define GPIOB_BSRR  (*(volatile uint32_t*)0x40020418)

static inline void Debug_GPIO_Init()
{
    RCC_AHB1ENR |= (1<<1);

    GPIOB_MODER |= (1<<(0*2));
    GPIOB_MODER |= (1<<(1*2));
    GPIOB_MODER |= (1<<(2*2));
    GPIOB_MODER |= (1<<(3*2));
    GPIOB_MODER |= (1<<(4*2));
}

static inline void SysTick_Handler()
{
    extern volatile uint32_t system_tick;
    system_tick++;
}

static inline void SysTick_Init()
{
    SYST_RVR = 168000 - 1;
    SYST_CVR = 0;
    SYST_CSR = 7;
}

static inline void DWT_Init()
{
    DEMCR |= (1<<24);
    DWT_CYCCNT = 0;
    DWT_CTRL |= 1;
}

#endif
