CC		= gcc
CFLAGS	= -Wall

all: \
	problem1 \
	problem2 \
	problem3
	
problem1: problem1.c
	$(CC) $(CFLAGS) -o $@ $@.c

problem2: problem1 problem2.c
	$(CC) $(CFLAGS) -o $@ $@.c

problem3: problem3.c
	$(CC) $(CFLAGS) -o $@ $@.c

clean:
	rm -f *~ *.o a.out core problem1 problem2 problem3
