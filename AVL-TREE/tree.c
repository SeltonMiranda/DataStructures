#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

void criaAVL(AVL *raiz)
{
    *raiz = NULL;
}

void escreveArv(AVL raiz)
{
    if (raiz == NULL)
        return;

    escreveArv(raiz->esq);
    printf("item: %d\n", raiz->item);
    printf("bal: %d\n", raiz->bal);
    escreveArv(raiz->dir);
}

static AVL criaNo(itemArv v, AVL dir, AVL esq)
{
    AVL nodo = malloc(sizeof(Nodo));
    if (nodo == NULL) {
        fprintf(stderr, "Nao foi possivel alocar memoria para %d", v);
        exit(1);
    }
    nodo->esq = esq;
    nodo->dir = dir;
    nodo->item = v;
    nodo->bal = 0;
    return nodo;
}

// Rotações para balancear a árvore
static void rotacaoEsquerda(AVL *p) {
    AVL u = (*p)->dir;
    (*p)->dir = u->esq;
    u->esq = *p;
    (*p)->bal = 0;
    *p = u;
}

static void rotacaoDireita(AVL *p) {
    AVL u = (*p)->esq;
    (*p)->esq = u->dir;
    u->dir = *p;
    (*p)->bal = 0;
    *p = u;
}

static void rotacaoDuplaEsquerda(AVL *p) {
    AVL u = (*p)->dir;
    AVL v = u->esq;
    u->esq = v->dir;
    v->dir = u;
    (*p)->dir = v->esq;
    v->esq = *p;

    if (v->bal == 1) {
        (*p)->bal = 0;
        u->bal = -1;
    } else if (v->bal == -1) {
        (*p)->bal = 1;
        u->bal = 0;
    } else {
        (*p)->bal = 0;
        u->bal = 0;
    }
    *p = v;
    (*p)->bal = 0;
}

static void rotacaoDuplaDireita(AVL *p) {
    AVL u = (*p)->esq;
    AVL v = u->dir;
    u->dir = v->esq;
    v->esq = u;
    (*p)->esq = v->dir;
    v->dir = *p;

    if (v->bal == -1) {
        (*p)->bal = 0;
        u->bal = 1;
    } else if (v->bal == 1) {
        (*p)->bal = -1;
        u->bal = 0;
    } else {
        (*p)->bal = 0;
        u->bal = 0;
    }
    *p = v;
    (*p)->bal = 0;
}

// Função para balancear a árvore
static void balanceia(AVL *p) {
    if ((*p)->bal == -2) {
        if ((*p)->dir->bal <= 0) {
            rotacaoEsquerda(p);
        } else {
            rotacaoDuplaEsquerda(p);
        }
    } else if ((*p)->bal == 2) {
        if ((*p)->esq->bal >= 0) {
            rotacaoDireita(p);
        } else {
            rotacaoDuplaDireita(p);
        }
    }
}

// Função de inserção na árvore AVL
AVL inserir(itemArv v, AVL p, bool *mudouAltura) {
    if (p == NULL) {
        *mudouAltura = 1;
        return criaNo(v, NULL, NULL);
    }

    if (v < p->item) {
        p->esq = inserir(v, p->esq, mudouAltura);
        if (*mudouAltura) {
            p->bal++;  // Crescendo à esquerda, então incrementa
            if (p->bal == 0) {
                *mudouAltura = false;
            } else if (p->bal == 2) {
                balanceia(&p);
                *mudouAltura = false;
            }
        }
    } else if (v > p->item) {
        p->dir = inserir(v, p->dir, mudouAltura);
        if (*mudouAltura) {
            p->bal--;  // Crescendo à direita, então decrementa
            if (p->bal == 0) {
                *mudouAltura = false;
            } else if (p->bal == -2) {
                balanceia(&p);
                *mudouAltura = false;
            }
        }
    }

    return p;
}

AVL busca(itemArv k, AVL raiz)
{
    if (raiz == NULL) {
        return NULL;
    }

    if (k == raiz->item)
        return raiz;
    if (k < raiz->item)
        return busca(k, raiz->esq);
    return busca(k, raiz->dir);
}

static AVL buscaMaior(AVL p)
{
    AVL atual = p;
    while (atual->dir != NULL)
        atual = atual->dir;
    return atual;
}

static AVL removeR(AVL nodoRem, AVL p, bool *mudouH)
{
    AVL filho;
    if (p == nodoRem) {
        if (p->dir != NULL) 
            filho = p->dir;
        else 
            filho = p->esq;
        free(p);
        *mudouH = true;
        return filho;
    } else if (nodoRem->item < p->item) {
        p->esq = removeR(nodoRem, p->esq, mudouH);
        if (*mudouH) {
            p->bal--;
            if (p->bal <= -2)
                balanceia(&p);
            if (p->bal != 0)
                *mudouH = false;
        }
    } else {
        p->dir = removeR(nodoRem, p->dir, mudouH);
        if (*mudouH) {
            p->bal++;
            if (p->bal >= 2)
                balanceia(&p);
            if (p->bal != 0)
                *mudouH = false;
        }
    }
    return p;
}

void remover(itemArv k, AVL *raiz)
{
    AVL nodoK, nodoRem;
    itemArv itemRem;
    bool mudouH;

    nodoK = busca(k, *raiz);
    if (nodoK == NULL)
        return;

    if (nodoK->dir == NULL || nodoK->esq == NULL)
        nodoRem = nodoK;
    else
        nodoRem = buscaMaior(nodoK->esq);
    itemRem = nodoRem->item;

    *raiz = removeR(nodoRem, *raiz, &mudouH);
    if (itemRem != k)
        nodoK->item = itemRem;
    return;
}

void freeAVL(AVL raiz)
{
    if (raiz == NULL)
        return;

    freeAVL(raiz->esq);
    freeAVL(raiz->dir);
    free(raiz);
}
