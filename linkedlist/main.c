
#include "liblist.h"

int main()
{
        ListNode list;
        int pos, value;

        createList(&list);
        if (listEmpty(&list)) {
                printf("List is empty.\n");
        } else {
                printf("List isn't empty.\n");
        }

        listAppend(&list ,20);
        listAppend(&list ,30);
        listAppend(&list ,14);
        listPrepend(&list, 3);
        listPrepend(&list, 48);
        printList(&list);
        printf("\n");

        if (listEmpty(&list)) {
                printf("List is empty.\n");
        } else {
                printf("List isn't empty.\n");
        }

        listInsertAt(&list, 10, 2);
        listInsertAt(&list, 33, 2);
        listInsertAt(&list, 81, 2);
        listInsertAt(&list, 72, 2);
        listInsertAt(&list, 19, 2);
        listInsertAt(&list, 101, -1);
        listInsertAt(&list, 358, 22);
        printList(&list);
        printf("\n");

        listRemove(&list, 3);
        listRemove(&list, 1);
        listRemove(&list, 5);
        listRemove(&list, 11);
        listRemove(&list, 25);
        printList(&list);
        printf("\n");

        listPeek(&list, 2, &value);
        printf("pos = 2 value = %d\n", value);
        listPeek(&list, 0, &value);
        printf("pos = 0 value = %d\n", value);
        listPeek(&list, 4, &value);
        printf("pos = 4 value = %d\n", value);
        listPeek(&list, 7, &value);
        printf("pos = 7 value = %d\n", value);
        listPeek(&list, 11, &value);
        printf("pos = 11 value = %d\n", value);

        pos = listSearch(&list, 101);
        printf("value = 101 pos = %d\n", pos);
        pos = listSearch(&list, 3);
        printf("value = 3 pos = %d\n", pos);
        pos = listSearch(&list, 20);
        printf("value = 20 pos = %d\n", pos);
        pos = listSearch(&list, 11);
        printf("value = 11 pos = %d\n", pos);
        pos = listSearch(&list, 999);
        printf("value = 999 pos = %d\n", pos);

        printf("size: %d\n", listSize(&list));
        freeList(&list);
        return 0;
}
