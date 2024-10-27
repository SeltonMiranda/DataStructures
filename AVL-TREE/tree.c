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

static void rotacaoEsq(AVL *p)
{
    AVL q = (*p)->dir;
    (*p)->dir = q->esq;
    q->esq = *p;
    *p = q;
}

static void rotacaoDir(AVL *p)
{
    AVL q = (*p)->esq;
    (*p)->esq = q->dir;
    q->dir = *p;
    *p = q;
}

static void balanceia(AVL *p)
{
    AVL filho, neto;

    if ((*p)->bal == 2) {
        filho = (*p)->esq;
        if (filho == NULL)
            return;
        if (filho->bal == 1) { // Rotação simples à direita
            rotacaoDir(p);
            (*p)->bal = 0;
            filho->bal = 0;
        } else if (filho->bal == -1) { // Rotação dupla esquerda-direita
            neto = filho->dir;
            if (neto == NULL)
                return;
            rotacaoEsq(&(*p)->esq);
            rotacaoDir(p);
            if (neto->bal == 1) {
                (*p)->bal = -1;
                filho->bal = 0;
            } else if (neto->bal == -1) {
                (*p)->bal = 0;
                filho->bal = 1;
            } else {
                (*p)->bal = 0;
                filho->bal = 0;
            }
            neto->bal = 0;
        }
    }

    if ((*p)->bal == -2) {
        filho = (*p)->dir;
        if (filho == NULL)
            return;
        if (filho->bal == -1) { // Rotação simples à esquerda
            rotacaoEsq(p);
            (*p)->bal = 0;
            filho->bal = 0;
        } else if (filho->bal == 1) { // Rotação dupla direita-esquerda
            neto = filho->esq;
            if (neto == NULL)
                return;
            rotacaoDir(&(*p)->dir);
            rotacaoEsq(p);
            if (neto->bal == 1) {
                (*p)->bal = 0;
                filho->bal = -1;
            } else if (neto->bal == -1) {
                (*p)->bal = 1;
                filho->bal = 0;
            } else {
                (*p)->bal = 0;
                filho->bal = 0;
            }
            neto->bal = 0;
        }
    }
}

AVL inserir(itemArv v, AVL p, bool *mudouAltura)
{
    if (p == NULL) {
        *mudouAltura = true;
        return criaNo(v, NULL, NULL);
    }

    if (v == p->item) {
        *mudouAltura = false;
        return p;
    }

    if (v < p->item) {
        p->esq = inserir(v, p->esq, mudouAltura);
        if (*mudouAltura) {
            p->bal++;
            if (p->bal == 2)
                balanceia(&p);
            if (p->bal == 0)
                *mudouAltura = false;
        } 
    } else {
        p->dir = inserir(v, p->dir, mudouAltura);
        if (*mudouAltura) {
            p->bal--;
            if (p->bal == -2)
                balanceia(&p);
            if (p->bal == 0)
                *mudouAltura = false;
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
            if (p->bal == -2)
                balanceia(&p);
            if (p->bal != 0)
                *mudouH = false;
        }
    } else {
        p->dir = removeR(nodoRem, p->dir, mudouH);
        if (*mudouH) {
            p->bal++;
            if (p->bal == 2)
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
