#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

void insert_test(BST *t)
{
    tInsert(t, 93);
    tInsert(t, 21);
    tInsert(t, 34);
    tInsert(t, 56);
    tInsert(t, 132);
    tInsert(t, 12);
    tInsert(t, 8);
    tInsert(t, 23);
    tInsert(t, 81);
    tInsert(t, 821);
    tInsert(t, 98);
    tInsert(t, 73);
    tInsert(t, 33);
    tInsert(t, 33);
    tInsert(t, 99);
}

void search_delete_test(BST *t)
{
    tDelete(t, tSearch(t, 98));
    tDelete(t, tSearch(t, 98));
    tDelete(t, tSearch(t, 73));
    tDelete(t, tSearch(t, 21));
    tDelete(t, tSearch(t, 821));
    tDelete(t, tSearch(t, 33));
    tDelete(t, tSearch(t, 92));
    tDelete(t, tSearch(t, 1000));
    tDelete(t, tSearch(t, 73));
}

int main()
{
    srand(0);
    BST t = NULL;

    insert_test(&t);
    inOrder(&t);
    printf("\n");

    Node current = tSearch(&t, 21);
    Node successor = tSuccessor(current);
    Node predecessor = tPredecessor(current);
    if (successor) printf("Successor of node %d: %d\n", current->key, successor->key);
    if (predecessor) printf("Predecessor of node %d: %d\n", current->key, predecessor->key);

    search_delete_test(&t);
    inOrder(&t);
    printf("\n");

    tFree(&t);
    t = NULL;
    return 0;
}
