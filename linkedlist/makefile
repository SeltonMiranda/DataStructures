CC=gcc
CFLAGS=-Wall -Wextra -pedantic --std=c17
MAIN=test
FILES=main.c liblist.c

.PHONY: all clean purge val

all:$(MAIN)

$(MAIN):$(FILES:.c=.o)
	$(CC) -o $@ $(FILES:.c=.o) $(CFLAGS)

main.o: main.c
	$(CC) -c $< $(CFLAGS)

liblist.o: liblist.c liblist.h
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf *.o *~ *.gch

purge:
	rm -rf *.o *~ *.gch $(MAIN) logs

val:
	valgrind --leak-check=full ./$(MAIN) 2> logs
