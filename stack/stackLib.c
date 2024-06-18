
#include "stackLib.h"

void stackInit(Stack *stack)
{
        *stack = NULL;
}

int stackEmpty(Stack *stack)
{
        return *stack == NULL ? 1 : 0;
}

static Stack createNode(int v)
{
        Stackp no = malloc(sizeof(Node));
        if (no == NULL) {
                fprintf(stderr, "createNode");
                exit(1);
        }

        no->val = v;
        no->next = NULL;
        
        return no;
}

void push(Stack *stack, int v)
{
        Stack p;

        p = createNode(v);
        p->next = *stack;
        *stack = p;
}

void pop(Stack *stack, int *v)
{
        if (stackEmpty(stack))
                return;
        Stack p;

        p = *stack;
        *v = p->val;
        *stack = p->next;
        free(p);
}

void printStack(Stack *stack)
{
        Stack q = *stack;
        while (q != NULL) {
                printf("%d ", q->val);
                q = q->next;
        }
}
