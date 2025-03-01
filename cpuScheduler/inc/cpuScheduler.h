#pragma once

#define _POSIX_C_SOURCE 200809L // to deal with the crazy "implicit declaration of getline()
// OR #define _GNU_SOURCE

#include <sys/types.h>

#include "processQueue.h"

#define INITIAL_CAPACITY 1

// contains parameters for functions implementing scheduling algorithms
typedef struct algorithmParams
{
    PROCESS *cpu; // reference to the currently executing process
    char algorithm[8]; // FCFS, SJF, SRTF, RR
    void (*step)(void *); // pointer to the step function we will call
    int quantum; // for RR
    int time; // current time tick
} ALGORITHM_PARAMS;

/***
 * reads processes from the input and adds them to the process table
 */
int readProcessTable();

/***
 * performs one step of the simulation
 */
void doStep(void (*func)(void *), void *);

/***
 * step for FCFS
 */
void fcfsStep(void *param);

/***
 * step for SJF
 */
void sjfStep(void *param);

/***
 * step for SRTF
 */
void srtfStep(void *param);

/***
 * step for RR
 */
void rrStep(void *param);

/***
 * displays time tick of the simulation
 */
void displayTimeTick(int, PROCESS*);