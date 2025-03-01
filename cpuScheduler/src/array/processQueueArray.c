#include "processQueue.h"

PROCESS* processTable;
int processTableSize = 0;
int processTableCapacity;

PROCESS** readyQueue;
int readyQueueSize = 0;
int readyQueueCapacity;

/***
 * constructor of the process table
 */
void
createProcessTable(int capacity)
{
    processTable = (PROCESS*) malloc(capacity * sizeof(PROCESS));
    processTableCapacity = capacity;
}

/***
 * constructor of the ready queue
 */
void 
createReadyQueue(int capacity)
{
    readyQueue = (PROCESS**) malloc(capacity * sizeof(PROCESS*));
    readyQueueCapacity = capacity;
}

/***
 * adds a process and expands the table if necessary
 */
void 
addProcessToTable(PROCESS process)
{
    // if the array is too small
    if (processTableSize >= processTableCapacity) {
        processTableCapacity *= 2; //double capacity
        processTable = (PROCESS*) realloc(processTable, processTableCapacity * sizeof(PROCESS));
    }

    // TODO: complete

    
    processTable[processTableSize++] = process;	

}

/***
 * display the processes table
 */
void
displayProcessTable()
{
    printf("PROCESSES:\n\nName    \tEntry\tBurst\n");
    for (int i = 0; i < processTableSize; i++)
    {
        printf("%-8s\t%3d   \t%3d   \n", processTable[i].name, processTable[i].entryTime, processTable[i].burstTime);
    }
    printf("\n");
}

/***
 * determines if any processes in the process table still need to execute
 */

bool 
processesLeftToExecute()
{
    // TODO: implement
    
    for(int i = 0; i < processTableSize; i++) {
    	if(processTable[i].burstTime != 0) {
    		return true;
    	}
    }
	
    return false; //return 0 if all processes are complete
}

/***
 * adds any processes that arrive at the current time to ready queue
 */
void 
addArrivingProcessesToReadyQueue(int time)
{
    // TODO: implement
    
    for(int i = 0; i < processTableSize; i++) {
    	if(processTable[i].entryTime == time) {
    		addProcessToReadyQueue(&processTable[i]);
    	}
    }
}

/***
 * adds a process to the ready queue and expands it if necessary
 */
void 
addProcessToReadyQueue(PROCESS* pointer)
{
    if (readyQueueSize >= readyQueueCapacity) //if array too small
    {
        readyQueueCapacity *= 2; //double capacity
        readyQueue = (PROCESS **) realloc(readyQueue, readyQueueCapacity * sizeof(PROCESS *));
    }

    // TODO: complete
    
    readyQueue[readyQueueSize++] = pointer;
}

/***
 * removes a process from the ready queue and fills the "hole"
 */
void 
removeProcessFromReadyQueue(PROCESS *p)
{
    // TODO: implement

	int i = 0;
	for(i = 0; i < readyQueueSize; i++) {
		if(readyQueue[i] == p) {
		   	break;
		}	
	}
	
	
	for(int j = i; j < readyQueueSize; j++) {
		readyQueue[j] = readyQueue[j+1];
	}

    readyQueueSize--;
}

/***
 * fetches the first process from the ready queue
 */
PROCESS* 
fetchFirstProcessFromReadyQueue()
{
    // TODO: implement
    if(readyQueueSize == 0) {
    	return NULL;
    }
    else {
    	PROCESS* p = readyQueue[0];
    	removeProcessFromReadyQueue(p);
    	return p;
    }
 
}

/***
 * finds the shortest job in the ready queue
 */
PROCESS*
findShortestProcessInReadyQueue()
{
    // TODO: implement
    
    if(readyQueueSize == 0) {
        return NULL;
    }

    int shorestIdx = 0;
    int shortestBurst = readyQueue[0]->burstTime;
    for(int i = 1; i < readyQueueSize; i++) {
        if(shortestBurst > readyQueue[i]->burstTime) {
            shortestBurst = readyQueue[i]->burstTime;
            shorestIdx = i;
        }
    }
    return readyQueue[shorestIdx];

}

/***
 * displays the contents of the ready queue
 */
void 
displayQueue()
{
    int i;
    printf("QUEUE: ");

    if (readyQueueSize <= 0) {
        printf("<empty>");
    } else {
        for (i = 0; i < readyQueueSize; i++) {
            printf("%s(%d) ", readyQueue[i]->name, readyQueue[i]->burstTime);
        }
    }
}

/***
 * calculates and prints the average wait time using information in the process table
 */
void
printAverageWaitTime()
{
    int i = 0;
    double sum = 0;

    for (i = 0; i < processTableSize; i++) {
        sum = sum + processTable[i].waitTime;
        printf("Process %s Wait Time: %.2lf\n", processTable[i].name, (double) processTable[i].waitTime);
    }

    printf("Average Wait Time: %.2lf\n", (sum / (double) processTableSize));
}

/***
 * clean up the process table
 */
void 
cleanUp()
{
    // TODO: implement
}





