MAIN=red-black
CFLAGS=-Wall -Wextra -pedantic -std=c17

all: $(MAIN)

$(MAIN): main.o tree.o
	gcc -o $(MAIN) main.o tree.o $(CFLAGS)

main.o: main.c
	gcc -c main.c $(CFLAGS)

tree.o: tree.c
	gcc -c tree.c $(CFLAGS)

clean:
	rm -f *.o $(MAIN) *.gch
