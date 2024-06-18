CC=gcc
CFLAGS=-Wall -Wextra -pedantic --std=c17
MAIN=test
FILES=main.c libqueue.c

.PHONY: all clean purge

all:$(MAIN)

$(MAIN): $(FILES:.c=.o)
	$(CC) -o $@ $(FILES:.c=.o) $(CFLAGS) -lm

main.o: main.c
	$(CC) -c $< $(CFLAGS)

liblista.o: liblista.c liblista.h
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf *.o *~ *.gch

purge:
	rm -rf *.o *~ *.gch $(MAIN) logs

val:
	valgrind --leak-check=full ./$(MAIN) 2> logs
