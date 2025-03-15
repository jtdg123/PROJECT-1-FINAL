#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scheduler.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <process_file> <algorithm> [quantum]\n", argv[0]);
        return EXIT_FAILURE;
    }
    Process processes[MAX_PROCESSES];
    int n;
    read_processes(argv[1], processes, &n);
    if (strcmp(argv[2], "FCFS") == 0) {
        fcfs(processes, n);
    } else if (strcmp(argv[2], "RR") == 0 && argc == 4) {
        round_robin(processes, n, atoi(argv[3]));
    } else {
        printf("Invalid scheduling algorithm!\n");
        return EXIT_FAILURE;
    }
    display_results(processes, n);
    return EXIT_SUCCESS;
}
