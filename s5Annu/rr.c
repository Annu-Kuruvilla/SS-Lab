#include <stdio.h>

#define MAX_PROCESSES 10

void roundRobinScheduling(int burstTime[], int arrivalTime[], int numProcesses, int timeQuantum) {
    int remainingTime[MAX_PROCESSES];
    int waitingTime[MAX_PROCESSES];
    int turnaroundTime[MAX_PROCESSES];
    int completedProcesses = 0;
    int currentTime = 0;

    for (int i = 0; i < numProcesses; i++) {
        remainingTime[i] = burstTime[i];
        waitingTime[i] = 0;
    }

    printf("\nProcess\tCompletion Time\tWaiting Time\tTurnaround Time\n");

    while (completedProcesses < numProcesses) {
        for (int i = 0; i < numProcesses; i++) {
            if (arrivalTime[i] <= currentTime && remainingTime[i] > 0) {
                if (remainingTime[i] <= timeQuantum) {
                    currentTime += remainingTime[i];
                    turnaroundTime[i] = currentTime - arrivalTime[i];
                    waitingTime[i] = turnaroundTime[i] - burstTime[i];
                    remainingTime[i] = 0;
                    completedProcesses++;
                    printf("%d\t%d\t\t%d\t\t%d\t%d\n", i + 1, arrivalTime, currentTime, waitingTime[i], turnaroundTime[i]);
                } else {
                    currentTime += timeQuantum;
                    remainingTime[i] -= timeQuantum;
                }
            }
        }
    }

    double avgWaitingTime = 0;
    double avgTurnaroundTime = 0;

    for (int i = 0; i < numProcesses; i++) {
        avgWaitingTime += waitingTime[i];
        avgTurnaroundTime += turnaroundTime[i];
    }

    avgWaitingTime /= numProcesses;
    avgTurnaroundTime /= numProcesses;

    printf("\nAverage Waiting Time: %.2lf\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2lf\n", avgTurnaroundTime);
}

int main() {
    int numProcesses;
    int timeQuantum;

    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    int burstTime[MAX_PROCESSES];
    int arrivalTime[MAX_PROCESSES];

    for (int i = 0; i < numProcesses; i++) {
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &arrivalTime[i]);

        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
    }

    printf("Enter time quantum: ");
    scanf("%d", &timeQuantum);

    roundRobinScheduling(burstTime, arrivalTime, numProcesses, timeQuantum);

    return 0;
}
