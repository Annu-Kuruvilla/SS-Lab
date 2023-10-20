#include<stdio.h>
 
// Structure to represent a process
struct Process {
    int pid;            // Process ID
    int arrival_time;   // Arrival Time
    int burst_time;     // Burst Time
    int priority;       // Priority
};
 
// Function to swap two processes
void swap(struct Process *x, struct Process *y) {
    struct Process temp = *x;
    *x = *y;
    *y = temp;
}
 
// Function to perform Priority Scheduling
void priorityScheduling(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Sort processes by priority
            if (processes[j].priority > processes[j + 1].priority) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
 
    int total_time = 0;
    float avg_waiting_time = 0;
    for (int i = 0; i < n; i++) {
        total_time += processes[i].burst_time;
        avg_waiting_time += total_time - processes[i].arrival_time;
    }
 
    avg_waiting_time /= n;
 
    printf("Process\tArrival Time\tBurst Time\tPriority\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%.2f\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].priority, avg_waiting_time);
    }
}
 
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
 
    struct Process processes[n];
 
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter Arrival Time for Process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        printf("Enter Priority for Process %d: ", i + 1);
        scanf("%d", &processes[i].priority);
    }
 
    priorityScheduling(processes, n);
 
    return 0;
}
