CC	= gcc
CFLAGS	= -g -Wall

all: problem1 problem2 problem2Timer

problem1: problem1.c
	$(CC) $(CFLAGS) -o problem1 problem1.c
	
problem2Timer: problem2Timer.c
	$(CC) $(CFLAGS) -o problem2Timer problem2Timer.c

problem2: problem2.c problem2Timer
	$(CC) $(CFLAGS) -o problem2 problem2.c

clean:
	rm -f *~ *.o a.out core *.txt problem1 problem2 problem2Timer
