
#include "stackLib.h"

int main() {
        Stack st;
        int size, value;
        stackInit(&st);

        if (stackEmpty(&st))
                printf("It is empty\n");
        else
                printf("It's not empty\n");

        size = rand() % 100 + 1;
        for (int i = 0; i < size; i++)
                push(&st, rand() % 100 + 1);
        printStack(&st);
        printf("\n");

        while (!stackEmpty(&st)) {
                pop(&st, &value);
                printf("value = %d\n", value);
        }

        return 0;
}
