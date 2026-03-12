
#include "scheduler.h"
#include "tasks.h"
#include "platform.h"

int main()
{
    Debug_GPIO_Init();
    SysTick_Init();
    DWT_Init();

    uint32_t sched_start;
    uint32_t sched_end;

    while(1)
    {
        GPIOB_BSRR = (1<<0);

        sched_start = DWT_CYCCNT;

        Scheduler_Run();

        sched_end = DWT_CYCCNT;

        GPIOB_BSRR = (1<<(0+16));

        uint32_t exec = sched_end - sched_start;

        if(exec > sched_wcet)
            sched_wcet = exec;
    }
}
