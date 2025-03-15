#ifndef SCHEDULER_H
#define SCHEDULER_H

#define MAX_PROCESSES 100

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
} Process;

void read_processes(const char *filename, Process processes[], int *n);
void fcfs(Process processes[], int n);
void round_robin(Process processes[], int n, int quantum);
void display_results(Process processes[], int n);

#endif
