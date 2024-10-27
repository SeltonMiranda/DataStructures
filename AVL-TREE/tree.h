#ifndef __AVL_TREE__
#define __AVL_TREE__

#include <stdbool.h>

typedef int itemArv;

typedef struct Nodo *ApNodo;

typedef ApNodo AVL;

typedef struct Nodo {
    ApNodo esq, dir;
    int bal;
    itemArv item;
} Nodo;

void criaAVL(AVL *raiz);
AVL inserir(itemArv v, AVL p, bool *mudouAltura);
AVL busca(itemArv k, AVL raiz);
void remover(itemArv k, AVL *raiz);
void escreveArv(AVL raiz);
void freeAVL(AVL raiz);

#endif // __AVL_TREE__
