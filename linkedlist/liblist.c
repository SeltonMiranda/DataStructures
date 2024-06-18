#include "liblist.h"

void createList(ListNode *list)
{
        *list = NULL;
}

int listEmpty(ListNode *list)
{
        return *list == NULL ? 1 : 0;
}

static ListNode createNode(int v)
{
        ListNode p = malloc(sizeof(Node));
        if (p == NULL) {
                fprintf(stderr, "createNode");
                exit(1);
        }

        p->val = v;
        p->next = NULL;
        p->prev = NULL;

        return p;
}

void listInsertAt(ListNode *list, int v, int pos)
{
        if (*list == NULL) {
               ListNode new = createNode(v);
               new->next = new;
               new->prev = new;
               (*list) = new;
               return;
        }

        if (pos == -1) {
                listPrepend(list, v);
                return;
        }

        if (pos >= listSize(list)) {
                listAppend(list, v);
                return;
        }

        ListNode new; 
        ListNode current;

        new = createNode(v);
        current = *list;
        for (int i = 0; i < pos; i++)
                current = current->next;

        ListNode previous = current->prev;
        previous->next = new;
        new->prev = previous;
        new->next = current;
        current->prev = new;
}


void listAppend(ListNode *list, int v)
{
        ListNode new = createNode(v);
        if (*list == NULL) {
                new->next = new;
                new->prev = new;
                *list = new;
                return;
        }

        ListNode last = (*list)->prev;
        last->next = new;
        new->prev = last;
        new->next = *list;
        (*list)->prev = new;
}

void listPrepend(ListNode *list, int v)
{
        ListNode new = createNode(v);
        if (*list == NULL) {
               new->next = new;
               new->prev = new;
               *list = new;
               return;
        }

        ListNode last = (*list)->prev;
        last->next = new;
        new->prev = last;
        new->next = *list;
        (*list)->prev = new;
        *list = new;
}
int listRemove(ListNode *list, int pos)
{
        if (*list == NULL)
                return 0;
        if (pos >= listSize(list))
                return 0;

        ListNode current;

        current = *list;
        for (int i = 0; i < pos; i++)
                current = current->next;

        ListNode previous;
        previous = current->prev;
        previous->next = current->next;
        current->next->prev = previous;
        free(current);
        return 1;
}
int listPeek(ListNode *list, int pos, int *e)
{
        if (*list == NULL)
                return 0;

        if (pos >= listSize(list))
                return 0;

        ListNode current;
        current = *list;
        for (int i = 0; i < pos; i++)
                current = current->next;
        *e = current->val;

        return 1;
}

int listSearch(ListNode *list, int v)
{
        if (*list == NULL)
                return -1;

        ListNode current;
        current = *list;
        int i = 0;
        while (current->val != v) {
              if (current == (*list)->prev)  
                      return -1;
              current = current->next;
              i++;
        }

        return i;
}

int listSize(ListNode *list)
{
        if (*list == NULL)
                return 0;

        ListNode current;
        ListNode head;

        current = (*list)->next;
        head = *list;
        int size = 1;
        while (current != head) {
                current = current->next;
                size++;
        }

        return size;
}

void freeList(ListNode *list)
{
        if (*list == NULL)
                return;

        ListNode current = (*list)->next;
        ListNode head = *list;

        while (current != head) {
                ListNode prev = current;
                current = current->next;
                free(prev);
        }

        free(*list);
        *list = NULL;
}

void printList(ListNode *list)
{
        if (*list == NULL)
                return;

        ListNode current;
        ListNode head;

        current = (*list)->next;
        head = *list;
        printf("%d ", head->val);
        while (current != head) {
                printf("%d ", current->val);
                current = current->next;
        }
}
