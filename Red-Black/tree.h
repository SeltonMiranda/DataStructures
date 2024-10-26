#ifndef __RBTREE__
#define __RBTREE__

typedef int itemArv;

typedef enum {RED, BLACK} tipoCor;

typedef struct nodo *ApNodo;
typedef struct nodo {
    ApNodo esq, dir;
    ApNodo pai;
    itemArv item;
    tipoCor cor;
} Nodo;

typedef ApNodo ArvRB;

extern ApNodo NodoNull;

void criaArvRB(ArvRB* );
void freeArvRB(ArvRB );
void escreveArvRB(ArvRB );
ArvRB insereArvRB(itemArv, ArvRB );
ArvRB buscaArvRB(itemArv, ArvRB );
int removeArvRB(itemArv, ArvRB* );

#endif // __RBTREE__
