# PROJECT-1-FINAL
# Process Scheduling Simulator

## Overview
This project simulates process scheduling using different CPU scheduling algorithms. Implemented algorithms:
- **First-Come, First-Served (FCFS)**
- **Round Robin (RR)**

## Directory Structure
```
OS-Process-Scheduling/
├── src/
│   ├── main.c  # Main scheduling program
│   ├── scheduler.h  # Header file for scheduling functions
│   ├── scheduler.c  # Implementation of scheduling algorithms
├── input/
│   ├── processes.txt  # Example input file
├── output/
│   ├── sample_output.txt  # Example Gantt chart output
├── docs/
│   ├── report.pdf  # Explanation of implementation
├── Makefile  # Compilation script
├── README.md  # Project details
├── .gitignore  # Ignore compiled files
```

## Compilation
Run the following command to compile the program:
```sh
make
```

## Usage
To run with FCFS:
```sh
./scheduler input/processes.txt FCFS
```
To run with Round Robin (Quantum = 2):
```sh
./scheduler input/processes.txt RR 2
```

## Example Input (`processes.txt`)
```
1 0 5 2
2 2 3 1
3 4 2 3
```

## Output Format
```
Gantt Chart:
| P1 | P2 | P3 |
0    5    8    10

PID  WT  TAT
1    0   5
2    3   6
3    4   6
```

## Cleaning Up
To remove compiled files:
```sh
make clean
