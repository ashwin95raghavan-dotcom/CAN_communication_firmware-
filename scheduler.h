
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdint.h>

typedef struct
{
    void (*task)(void);
    uint32_t period;
    uint32_t last_run;
}Task;

extern volatile uint32_t system_tick;
extern uint32_t sched_wcet;

void Scheduler_Run(void);

#endif
