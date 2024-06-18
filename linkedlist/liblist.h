#ifndef ___LIST___
#define ___LIST___

#include <stdio.h>
#include <stdlib.h>

typedef struct Node *ListNode;
typedef struct Node {
        int val;
        ListNode prev; 
        ListNode next; 
} Node;

void createList(ListNode *list);
int listEmpty(ListNode *list);
void listInsertAt(ListNode *list, int v, int pos);
void listAppend(ListNode *list, int v);
void listPrepend(ListNode *list, int v);
int listRemove(ListNode *list, int pos);
int listPeek(ListNode *list, int pos, int *e);
int listSearch(ListNode *list, int v);
int listSize(ListNode *list);
void freeList(ListNode *list);
void printList(ListNode *list);

#endif
