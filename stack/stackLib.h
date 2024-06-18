#ifndef __SSTACKLIB__
#define __SSTACKLIB__

#include <stdio.h>
#include <stdlib.h>

typedef struct Node *Stackp;
typedef struct Node {
        int val;
        Stackp next; 
} Node;

typedef Stackp Stack;

void stackInit(Stack *stack);
int stackEmpty(Stack *stack);
void push(Stack *stack, int v);
void pop(Stack *stack, int *v);
void printStack(Stack *stack);

#endif
