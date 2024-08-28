#ifndef AVL_H
#define AVL_H

typedef struct Nodo *ApNodo;
typedef ApNodo AVL;
typedef struct Nodo {
    ApNodo parent;    
    ApNodo left;    
    ApNodo right;    
    int height;
    int key;
} Nodo;

// Inserts a new node into AVL tree
AVL avl_insert(AVL *t, int key);

// Removes a node from AVL tree
AVL avl_delete(AVL *t, int key);

// Prints in order Path
void inOrder(AVL *t);

// Frees the AVL tree
void avl_free(AVL *t);
#endif // AVL_H
