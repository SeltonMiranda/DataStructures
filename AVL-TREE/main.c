#include <stdio.h>
#include "tree.h"

int main()
{
    AVL arv;
    criaAVL(&arv);
    bool mudouAltura;
    
    arv = inserir(10, arv, &mudouAltura);
    arv = inserir(20, arv, &mudouAltura);
    arv = inserir(21, arv, &mudouAltura);
    arv = inserir(13, arv, &mudouAltura);
    arv = inserir(8, arv, &mudouAltura);
    arv = inserir(49, arv, &mudouAltura);
    arv = inserir(30, arv, &mudouAltura);
    arv = inserir(33, arv, &mudouAltura);

    escreveArv(arv);

    printf("------------------------------\n");
    //remover(10, &arv);
    //remover(20, &arv);
    //remover(21, &arv);
    ////remover(8, &arv);
    ////remover(13, &arv);
    //remover(49, &arv);
    //remover(30, &arv);
    //remover(33, &arv);

    printf("bal: %d\n", arv->bal);
    printf("bal: %d\n", arv->esq->bal);

    freeAVL(arv);

    return 0;
}
