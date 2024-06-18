        
#include "libqueue.h"

void createQueue(Queue *q)
{
        q->first = NULL;
        q->last = NULL;
}

int queueEmpty(Queue q)
{
        return q.first == NULL ? 1 : 0;
}

static pNoQueue createNoQueue(int v)
{
        pNoQueue p;

        p = malloc(sizeof(pNoQueue));
        p->val = v;
        p->next = NULL;
        return p;
}

void enqueue(Queue *q, int v)
{
        pNoQueue p;
        
        p = createNoQueue(v);
        if (q->first == NULL) {
                q->first = p;
                q->last = p;
        } else {
                q->last->next = p;
                q->last = p;
        }
}

void dequeue(Queue *q, int *v)
{
        if (queueEmpty(*q))
                return;

        pNoQueue p;
        p = q->first;
        q->first = p->next;
        *v = p->val;
        free(p);
}

void printQueue(Queue *q)
{
        pNoQueue current;

        current = q->first;
        while (current != NULL) {
                printf("%d ", current->val);
                current = current->next;
        }
}
