#ifndef __LIBQUEUE__
#define __LIBQUEUE__

// p stands for pointer

#include <stdio.h>
#include <stdlib.h>

typedef struct Node *pNoQueue;
typedef struct Node {
        int val;
        pNoQueue next;
} Node;

typedef struct Queue {
        pNoQueue first, last;
} Queue;

void createQueue(Queue *q);
int queueEmpty(Queue q);
void enqueue(Queue *q, int v);
void dequeue(Queue *q, int *v);
void printQueue(Queue *q);

#endif
