#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include <stdint.h>

/* CPU & Tick */
#define configCPU_CLOCK_HZ            ( 600000000UL )
#define configTICK_RATE_HZ            ( ( TickType_t ) 1000 )

/* Scheduler */
#define configUSE_PREEMPTION          1
#define configUSE_TIME_SLICING        1
#define configMAX_PRIORITIES          5
#define configMINIMAL_STACK_SIZE      128
#define configTOTAL_HEAP_SIZE         ( 64 * 1024 )
#define configMAX_TASK_NAME_LEN       16

/* Features */
#define configUSE_MUTEXES             1
#define configUSE_COUNTING_SEMAPHORES 1
#define configUSE_RECURSIVE_MUTEXES   1
#define configUSE_QUEUE_SETS          1

/* Hooks */
#define configUSE_IDLE_HOOK           0
#define configUSE_TICK_HOOK           0
#define configCHECK_FOR_STACK_OVERFLOW 2

/* Software timer */
#define configUSE_TIMERS              1
#define configTIMER_TASK_PRIORITY     2
#define configTIMER_QUEUE_LENGTH      10
#define configTIMER_TASK_STACK_DEPTH  256

/* API Inclusion */
#define INCLUDE_vTaskDelay            1
#define INCLUDE_vTaskDelayUntil       1
#define INCLUDE_vTaskDelete           1
#define INCLUDE_vTaskSuspend          1
#define INCLUDE_xTaskGetCurrentTaskHandle 1

/* Cortex-M7 */
#define configPRIO_BITS               4
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY 15
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY 5
#define configKERNEL_INTERRUPT_PRIORITY \
    ( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )
#define configMAX_SYSCALL_INTERRUPT_PRIORITY \
    ( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )

#endif
