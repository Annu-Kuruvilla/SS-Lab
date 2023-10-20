#include <stdio.h>

#define MAX_PROCESSES 10

struct Process {
    int processID;
    int arrivalTime;
    int burstTime;
};

void fcfsScheduling(struct Process processes[], int numProcesses) {
    int currentTime = 0;
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    for (int i = 1; i <= numProcesses; i++) {
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime;
        }

        int completionTime = currentTime + processes[i].burstTime;
        int turnaroundTime = completionTime - processes[i].arrivalTime;
        int waitingTime = turnaroundTime - processes[i].burstTime;

        totalWaitingTime += waitingTime;
        totalTurnaroundTime += turnaroundTime;

        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].processID, processes[i].arrivalTime, processes[i].burstTime,
               completionTime, turnaroundTime, waitingTime);

        currentTime = completionTime;
    }

    double avgWaitingTime = (double)totalWaitingTime / numProcesses;
    double avgTurnaroundTime = (double)totalTurnaroundTime / numProcesses;

    printf("\nAverage Waiting Time: %.2lf\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2lf\n", avgTurnaroundTime);
}

int main() {
    int numProcesses;

    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    struct Process processes[MAX_PROCESSES];

    for (int i = 1; i <= numProcesses; i++) {
        printf("Enter arrival time for process %d: ", i );
        scanf("%d", &processes[i].arrivalTime);

        printf("Enter burst time for process %d: ", i );
        scanf("%d", &processes[i].burstTime);

        processes[i].processID = i;
    }

    fcfsScheduling(processes, numProcesses);

    return 0;
}
