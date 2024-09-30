CC = gcc
CFLAGS = -Wall

all: fib

fib: fib.o
	$(CC) $(CFLAGS) -o fib fib.o

fib.o: fib.c
	$(CC) $(CFLAGS) -c fib.c

clean:
	rm -f fib fib.o
