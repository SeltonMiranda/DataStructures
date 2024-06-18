#ifndef ___LIBTREE___
#define ___LIBTREE___

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// p stands for pointer

typedef struct Node *pNodeTree;
typedef struct Node {
       int val;
       pNodeTree left, right;
} Node;

typedef pNodeTree binTree;

void createTree(binTree *arv);
int emptyTree(binTree *arv);
void preOrdem(binTree *arv);
void postOrdem(binTree *arv);
void Ordem(binTree *arv);
void printTree(binTree *arv);
int insertTree(int v, binTree *arv);
int heightTree(binTree *arv);
int countNoTree(binTree *arv);
int completeTree(binTree *arv);
int pathLength(binTree *arv, int h);
int extPathLength(binTree *arv, int h);
int intPathLength(binTree *arv, int h);
void freeTree(binTree *arv);

#endif
