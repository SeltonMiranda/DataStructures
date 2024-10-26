#include "tree.h"
#include <stdio.h>

int main() {
    ArvRB raiz;
    criaArvRB(&raiz);
    raiz = insereArvRB(50, raiz);
    raiz = insereArvRB(30, raiz);
    raiz = insereArvRB(20, raiz);
    raiz = insereArvRB(10, raiz);
    raiz = insereArvRB(25, raiz);
    raiz = insereArvRB(60, raiz);
    raiz = insereArvRB(55, raiz);
    raiz = insereArvRB(22, raiz);
    raiz = insereArvRB(52, raiz);
    raiz = insereArvRB(51, raiz);
    raiz = insereArvRB(48, raiz);
    escreveArvRB(raiz);
    removeArvRB(60, &raiz);
    removeArvRB(50, &raiz);
    removeArvRB(30, &raiz);
    removeArvRB(20, &raiz);
    removeArvRB(10, &raiz);
    removeArvRB(51, &raiz);
    removeArvRB(52, &raiz);
    removeArvRB(48, &raiz);
    removeArvRB(25, &raiz);
    removeArvRB(55, &raiz);
    removeArvRB(22, &raiz);
    printf("--------------------------\n");
    escreveArvRB(raiz);
    printf("--------------------------\n");

    raiz = insereArvRB(50, raiz);
    raiz = insereArvRB(30, raiz);
    raiz = insereArvRB(20, raiz);
    raiz = insereArvRB(10, raiz);
    raiz = insereArvRB(25, raiz);
    raiz = insereArvRB(60, raiz);
    raiz = insereArvRB(55, raiz);
    raiz = insereArvRB(22, raiz);
    raiz = insereArvRB(52, raiz);
    raiz = insereArvRB(51, raiz);
    raiz = insereArvRB(48, raiz);
    escreveArvRB(raiz);
    printf("--------------------------\n");
    freeArvRB(raiz);
    return 0;
}
