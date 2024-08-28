#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main()
{
    srand(0);
    AVL root = NULL;
    root = avl_insert(&root, 92);
    root = avl_insert(&root, 41);
    root = avl_insert(&root, 91);
    root = avl_insert(&root, 34);
    root = avl_insert(&root, 74);
    root = avl_insert(&root, 82);
    inOrder(&root);
    printf("\n");
    root = avl_delete(&root, 91);
    root = avl_delete(&root, 92);
    root = avl_delete(&root, 93);
    inOrder(&root);
    printf("\n");
    avl_free(&root);
    return 0;
}
