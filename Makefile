CC = gcc
CFLAGS = -Wall -Wextra

all: scheduler

scheduler: main.o scheduler.o
	$(CC) $(CFLAGS) -o scheduler main.o scheduler.o

main.o: src/main.c src/scheduler.h
	$(CC) $(CFLAGS) -c src/main.c

scheduler.o: src/scheduler.c src/scheduler.h
	$(CC) $(CFLAGS) -c src/scheduler.c

clean:
	rm -f *.o scheduler
