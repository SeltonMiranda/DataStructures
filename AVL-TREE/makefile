CFLAGS= -Wall -Wextra -pedantic -std=c17
MAIN=AVL-TREE

all:$(MAIN)

$(MAIN): main.o tree.o
	gcc -o $@ main.o tree.o $(CFLAGS)

main.o: main.c
	gcc -c $< $(CFLAGS)

tree.o: tree.c 
	gcc -c $< $(CFLAGS)

clean:
	rm -f $(MAIN) *.o *.gch
