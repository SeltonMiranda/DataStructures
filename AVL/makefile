CFLAGS= -Wall -Wextra -pedantic -std=c11
MAIN=AVL

all:$(MAIN)

$(MAIN): main.o avl.o
	gcc -o $@ main.o avl.o $(CFLAGS)

main.o: main.c
	gcc -c $< $(CFLAGS)

avl.o: avl.c avl.h
	gcc -c $< $(CFLAGS)

clean:
	rm -f $(MAIN) *.o
