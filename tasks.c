
#include "tasks.h"
#include "platform.h"

void Sensors_Read()
{
    GPIOB_BSRR = (1<<1);
    for(volatile int i=0;i<5000;i++);
    GPIOB_BSRR = (1<<(1+16));
}

void Cooling_Control()
{
    GPIOB_BSRR = (1<<2);
    for(volatile int i=0;i<2000;i++);
    GPIOB_BSRR = (1<<(2+16));
}

void Actuator_Manager()
{
    GPIOB_BSRR = (1<<3);
    for(volatile int i=0;i<1500;i++);
    GPIOB_BSRR = (1<<(3+16));
}

void Diagnostics_Task()
{
    for(volatile int i=0;i<1000;i++);
}

void CAN_Task()
{
    GPIOB_BSRR = (1<<4);
    for(volatile int i=0;i<4000;i++);
    GPIOB_BSRR = (1<<(4+16));
}
