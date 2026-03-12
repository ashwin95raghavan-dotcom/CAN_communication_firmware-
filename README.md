
# BCM Cooperative Scheduler (Automotive ECU)

Lightweight cooperative scheduler for a Battery Cooling Module ECU.

## Features

- Deterministic periodic task scheduling
- WCET measurement using ARM DWT cycle counter
- GPIO instrumentation for logic analyzer measurement
- 1ms SysTick scheduler base

## Target

STM32F4 ARM Cortex‑M4 @168MHz

## Tasks

Sensors_Read – 5ms  
Cooling_Control – 10ms  
Actuator_Manager – 10ms  
Diagnostics_Task – 50ms  
CAN_Task – 100ms

## Purpose

Demonstrates real-time embedded scheduling, execution time analysis,
and GPIO timing instrumentation for automotive ECU firmware.
