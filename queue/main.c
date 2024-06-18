#include <stdio.h>
#include <time.h>

#include "libqueue.h"

int main()
{
        srand(1);
        int x;
        Queue queue;
        createQueue(&queue);

        if (queueEmpty(queue)) {
                printf("Queue is empty.\n");
        } else {
                printf("Queue isn't empty.\n");
        }

        for (int i = 0; i < 50; i++)
                enqueue(&queue, rand() % 100 + 1);
        printQueue(&queue);
        printf("\n");

        if (queueEmpty(queue)) {
                printf("Queue is empty.\n");
        } else {
                printf("Queue isn't empty.\n");
        }

        while (!queueEmpty(queue)) {
                dequeue(&queue, &x);
                printf("%d ", x);
        }
        printf("\n");

        if (queueEmpty(queue)) {
                printf("Queue is empty.\n");
        } else {
                printf("Queue isn't empty.\n");
        }

        return 0;
}
