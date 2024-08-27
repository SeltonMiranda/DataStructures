MAIN=bst
CFLAGS= -Wall -Wextra -pedantic -std=c11

all: $(MAIN)

$(MAIN): main.o bst.o
	gcc -o $@ main.o bst.o $(CFLAGS)

main.o: main.c
	gcc -c $< $(CFLAGS)

bst.o: bst.c bst.h
	gcc -c $< $(CFLAGS)

clean:
	rm -f *.o $(MAIN)
