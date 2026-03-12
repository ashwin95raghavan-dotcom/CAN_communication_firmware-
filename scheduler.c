
#include "scheduler.h"
#include "tasks.h"

volatile uint32_t system_tick = 0;
uint32_t sched_wcet = 0;

#define TASK_COUNT 5

Task task_table[] =
{
    {Sensors_Read,      5, 0},
    {Cooling_Control,  10, 0},
    {Actuator_Manager, 10, 0},
    {Diagnostics_Task, 50, 0},
    {CAN_Task,        100, 0}
};

void Scheduler_Run()
{
    for(int i=0;i<TASK_COUNT;i++)
    {
        if((system_tick - task_table[i].last_run) >= task_table[i].period)
        {
            task_table[i].task();
            task_table[i].last_run = system_tick;
        }
    }
}
