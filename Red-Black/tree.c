#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

Nodo nodo_null = {
    .esq = NULL, .dir = NULL, .pai = NULL,
    .item = -1,
    .cor = BLACK
};

ApNodo NodoNull = &nodo_null;

static ApNodo criaNodo(itemArv v, ApNodo esq, ApNodo dir, ApNodo pai, tipoCor cor)
{
    ArvRB novo = malloc(sizeof(Nodo));
    if (novo == NULL) {
        fprintf(stderr, "Não conseguiu alocar para %d\n", v);
        exit(1);
    }

    novo->pai = pai;
    novo->esq = esq;
    novo->dir = dir;
    novo->item = v;
    novo->cor = cor;
    return novo;
}

static void rotacaoEsq(ArvRB p, ArvRB* raiz) {
    ArvRB novoPai = p->dir; // Novo pai será o filho direito do nó p

    // Conectar o filho esquerdo do novo pai ao filho direito de p
    p->dir = novoPai->esq;
    if (novoPai->esq != NodoNull) {
        novoPai->esq->pai = p; // Atualiza o pai do filho esquerdo
    }

    // Atualiza o pai de novo pai
    novoPai->pai = p->pai;

    // Verifica se p é raiz para atualizar a raiz da árvore
    if (p->pai == NodoNull) {
        *raiz = novoPai; // Atualiza a raiz
    } else if (p == p->pai->esq) {
        p->pai->esq = novoPai; // Atualiza o filho esquerdo do pai de p
    } else {
        p->pai->dir = novoPai; // Atualiza o filho direito do pai de p
    }

    // Finaliza a rotação
    novoPai->esq = p; // p se torna o filho esquerdo do novo pai
    p->pai = novoPai; // Atualiza o pai de p
}

static void rotacaoDir(ArvRB p, ArvRB* raiz) {
    ArvRB novoPai = p->esq; // Novo pai será o filho esquerdo do nó p

    // Conectar o filho direito do novo pai ao filho esquerdo de p
    p->esq = novoPai->dir;
    if (novoPai->dir != NodoNull) {
        novoPai->dir->pai = p; // Atualiza o pai do filho direito
    }

    // Atualiza o pai de novo pai
    novoPai->pai = p->pai;

    // Verifica se p é raiz para atualizar a raiz da árvore
    if (p->pai == NodoNull) {
        *raiz = novoPai; // Atualiza a raiz
    } else if (p == p->pai->dir) {
        p->pai->dir = novoPai; // Atualiza o filho direito do pai de p
    } else {
        p->pai->esq = novoPai; // Atualiza o filho esquerdo do pai de p
    }

    // Finaliza a rotação
    novoPai->dir = p; // p se torna o filho direito do novo pai
    p->pai = novoPai; // Atualiza o pai de p
}



ArvRB buscaArvRB(itemArv v, ArvRB p)
{
    if (p == NodoNull)
        return NULL;
    if (v == p->item)
        return p;
    if (v < p->item)
        return buscaArvRB(v, p->esq);
    return buscaArvRB(v, p->dir);
}

void criaArvRB(ArvRB* raiz)
{
    (*raiz) = NodoNull;
}

void escreveArvRB(ArvRB raiz) 
{
    if (raiz == NodoNull) {
        return;
    }
    
    escreveArvRB(raiz->esq);
    if (raiz->cor == RED) {
        printf("item: %d , cor: RED\n", raiz->item);
    } else {
        printf("item: %d , cor: BLACK\n", raiz->item);
    }
    escreveArvRB(raiz->dir);
}

static ArvRB insereR(itemArv v, ArvRB raiz, ApNodo pai, ApNodo *novoNodo)
{
    if (raiz == NodoNull) {
        *novoNodo = criaNodo(v, NodoNull, NodoNull, pai, RED);
        return *novoNodo;
    }

    if (v == raiz->item) {
        return raiz; 
    } else if (v < raiz->item) {
        raiz->esq = insereR(v, raiz->esq, raiz, novoNodo);
    } else {
        raiz->dir = insereR(v, raiz->dir, raiz, novoNodo);
    }

    return raiz;
}

static void arrumaRBInsercao(ArvRB* raiz, ArvRB p)
{
    ArvRB pai, avo, tio;

    while (p != *raiz && p->pai->cor == RED ) {
        pai = p->pai; 
        avo = pai->pai;

        // Caso em que o pai é subárvore esquerda
        if (pai == avo->esq) {
            tio = avo->dir;
            // split //
            if (tio->cor == RED) {
                pai->cor = BLACK;
                tio->cor = BLACK;
                avo->cor = RED;
                p = avo;
            } else {
                // Caso esq-dir // 
                if (p == pai->dir) {
                    p = p->pai;
                    rotacaoEsq(p, raiz);
                    pai = p->pai;
                }
                // Caso esq-esq // 
                pai->cor = BLACK; 
                avo->cor = RED;
                rotacaoDir(avo, raiz);
            }
        } else {
            // Caso em que o pai é subárvore direita
            tio = avo->esq;

            // Caso de split
            if (tio->cor == RED) {
                pai->cor = BLACK;
                tio->cor = BLACK;
                avo->cor = RED;
                p = avo;
            } else {
                
                // Caso esq-dir
                if (p == pai->esq) {
                    p = p->pai;
                    rotacaoDir(p, raiz);
                    pai = p->pai;
                }
                
                // Caso dir-dir
                pai->cor = BLACK;
                avo->cor = RED;
                rotacaoEsq(avo, raiz);
            }
        }
    }
    (*raiz)->cor = BLACK;
}

ArvRB insereArvRB(itemArv v, ArvRB raiz)
{
    ArvRB novoNodo;

    if (raiz == NodoNull) 
        return criaNodo(v, NodoNull, NodoNull, NodoNull, BLACK);
    if (v == raiz->item)
        return raiz;
    if (v < raiz->item)
        raiz->esq = insereR(v, raiz->esq, raiz, &novoNodo);
    else 
        raiz->dir = insereR(v, raiz->dir, raiz, &novoNodo);
    arrumaRBInsercao(&raiz, novoNodo);
    return raiz;
}

static ArvRB sucessor(ArvRB p)
{
    if (p->dir != NodoNull) {
        ArvRB q = p->dir;
        while (q->esq != NodoNull) q = q->esq; 
        return q;
    }

    ArvRB q = p->pai;
    while (q != NodoNull && p == q->dir) {
        p = q;
        q = q->pai;
    }
    return q;
}

static void trocaFilho(ArvRB pai, ArvRB nodoRem, ArvRB filho)
{
    if (pai->esq == nodoRem)
        pai->esq = filho;
    else
        pai->dir = filho;

    if (filho != NodoNull)
        filho->pai = pai;
}

static void arrumaRBRemocao(ArvRB* raiz, ArvRB p) {
    ArvRB pai, irmao;

    while (p != *raiz && p->cor == BLACK) {
        pai = p->pai;

        if (p == pai->esq) { // Caso de duplo preto à esquerda
            irmao = pai->dir;

            if (irmao->cor == RED) { // Caso 1: irmão vermelho
                irmao->cor = BLACK;
                pai->cor = RED;
                rotacaoEsq(pai, raiz);
                irmao = pai->dir;
            }

            if (irmao->esq->cor == BLACK && irmao->dir->cor == BLACK) { // Caso 2: irmão preto com filhos pretos
                irmao->cor = RED;
                p = pai;
            } else {
                if (irmao->esq->cor == RED) { // Caso 3: irmão preto com filho esquerdo vermelho
                    irmao->cor = RED;
                    irmao->esq->cor = BLACK;
                    rotacaoDir(irmao, raiz);
                    irmao = pai->dir;
                }
                // Caso 4: irmão preto com filho direito vermelho
                irmao->cor = pai->cor;
                pai->cor = BLACK;
                irmao->dir->cor = BLACK;
                rotacaoEsq(pai, raiz);
                p = *raiz;
            }
        } else { // Caso simétrico de duplo preto à direita
            irmao = pai->esq;

            if (irmao->cor == RED) { // Caso 1: irmão vermelho
                irmao->cor = BLACK;
                pai->cor = RED;
                rotacaoDir(pai, raiz);
                irmao = pai->esq;
            }

            if (irmao->dir->cor == BLACK && irmao->esq->cor == BLACK) { // Caso 2: irmão preto com filhos pretos
                irmao->cor = RED;
                p = pai;
            } else {
                if (irmao->dir->cor == RED) { // Caso 3: irmão preto com filho direito vermelho
                    irmao->cor = RED;
                    irmao->dir->cor = BLACK;
                    rotacaoEsq(irmao, raiz);
                    irmao = pai->esq;
                }
                // Caso 4: irmão preto com filho esquerdo vermelho
                irmao->cor = pai->cor;
                pai->cor = BLACK;
                irmao->esq->cor = BLACK;
                rotacaoDir(pai, raiz);
                p = *raiz;
            }
        }
    }

    p->cor = BLACK;
}


int removeArvRB(itemArv v, ArvRB* raiz)
{
    ArvRB nodoV, nodoRem, filho;

    nodoV = buscaArvRB(v, *raiz);
    if (nodoV == NULL)
        return 0;
    if (nodoV->esq == NodoNull || nodoV->dir == NodoNull)
        nodoRem = nodoV;
    else
        nodoRem = sucessor(nodoV);
    if (nodoRem->esq != NodoNull) filho = nodoRem->esq;
    else filho = nodoRem->dir;
    filho->pai = nodoRem->pai;

    if (nodoRem->pai == NodoNull) 
        *raiz = filho;
    else
        trocaFilho(nodoRem->pai, nodoRem, filho);
    if (nodoV != nodoRem)
        nodoV->item = nodoRem->item;
    if (nodoRem->cor == BLACK){
        arrumaRBRemocao(raiz, filho);
    }
    free(nodoRem);
    return 1;
}

void freeArvRB(ArvRB raiz)
{
    if (raiz == NodoNull)
        return;

    freeArvRB(raiz->esq);
    freeArvRB(raiz->dir);
    free(raiz);
}


