#include <stdio.h>
#include <stdlib.h>
#include "scheduler.h"

void read_processes(const char *filename, Process processes[], int *n) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    *n = 0;
    while (fscanf(file, "%d %d %d %d", &processes[*n].pid, &processes[*n].arrival_time,
                  &processes[*n].burst_time, &processes[*n].priority) == 4) {
        (*n)++;
    }
    fclose(file);
}

void fcfs(Process processes[], int n) {
    int time = 0;
    printf("\nGantt Chart: \n");
    for (int i = 0; i < n; i++) {
        if (time < processes[i].arrival_time)
            time = processes[i].arrival_time;
        printf("| P%d ", processes[i].pid);
        processes[i].waiting_time = time - processes[i].arrival_time;
        time += processes[i].burst_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
    printf("|\n");
}

void round_robin(Process processes[], int n, int quantum) {
    int time = 0, remaining[n], done;
    for (int i = 0; i < n; i++) remaining[i] = processes[i].burst_time;
    printf("\nGantt Chart: \n");
    do {
        done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                done = 0;
                printf("| P%d ", processes[i].pid);
                int exec_time = (remaining[i] > quantum) ? quantum : remaining[i];
                time += exec_time;
                remaining[i] -= exec_time;
                if (remaining[i] == 0)
                    processes[i].turnaround_time = time - processes[i].arrival_time;
            }
        }
    } while (!done);
    printf("|\n");
}

void display_results(Process processes[], int n) {
    printf("\nPID  WT  TAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d    %d   %d\n", processes[i].pid, processes[i].waiting_time, processes[i].turnaround_time);
    }
}
