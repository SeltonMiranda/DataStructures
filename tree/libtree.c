
#include "libtree.h"

void createTree(binTree *tree)
{
        *tree = NULL;
}

int emptyTree(binTree *tree)
{
        return *tree == NULL ? 1 : 0;
}

void preOrdem(binTree *tree)
{
        if (*tree == NULL)
                return;
        printf("%d ", (*tree)->val);
        preOrdem(&(*tree)->left);
        preOrdem(&(*tree)->right);
}

void Ordem(binTree *tree)
{
        if (*tree == NULL)
                return;
        Ordem(&(*tree)->left);
        printf("%d ", (*tree)->val);
        Ordem(&(*tree)->right);
}

void postOrdem(binTree *tree)
{
        if (*tree == NULL)
                return;
        postOrdem(&(*tree)->left);
        postOrdem(&(*tree)->right);
        printf("%d ", (*tree)->val);
}

static pNodeTree createNode(int val)
{
        pNodeTree new = malloc(sizeof(Node));
        if (new == NULL) {
                fprintf(stderr, "createNode");
                exit(1);
        }

        new->left = NULL;
        new->right = NULL;
        new->val = val;

        return new;
}

int insertTree(int val, binTree *tree)
{
        if (*tree == NULL) {
               *tree = createNode(val); 
        } else if (val < (*tree)->val) {
                insertTree(val, &(*tree)->left);
        } else if (val > (*tree)->val) {
                insertTree(val, &(*tree)->right);
        } else {
                return 0;
        }

        return 1;
}

void printTree(binTree *tree)
{
        if (*tree == NULL)
                return;
        printf("%d ", (*tree)->val);
        printTree(&(*tree)->left);
        printTree(&(*tree)->right);
}

int heightTree(binTree *tree)
{
        int he, hd;

        if (*tree == NULL)
                return 0;
        he = heightTree(&(*tree)->left);
        hd = heightTree(&(*tree)->right);
        if (he > hd)
                return he + 1;
        else
                return hd + 1;
}

int countNoTree(binTree *tree)
{
        if (*tree == NULL)
                return 0;
        return 1 + countNoTree(&(*tree)->left) + countNoTree(&(*tree)->right);
}

int completeTree(binTree *tree)
{
        if (countNoTree(tree) == pow(2, heightTree(tree) - 1))
                return 1;
        return 0;
}

int pathLength(binTree *tree, int h)
{
        if (*tree == NULL)
                return h;
        return h + pathLength(&(*tree)->left, h+1)
                + pathLength(&(*tree)->right, h+1);
}

int intPathLength(binTree *tree, int h)
{
        if (*tree == NULL)
                return 0;
        return h + intPathLength(&(*tree)->left, h+1)
                + intPathLength(&(*tree)->right, h+1);
}

int extPathLength(binTree *tree, int h)
{
        if (*tree == NULL)
                return h;
        return extPathLength(&(*tree)->left, h+1)
                + extPathLength(&(*tree)->right, h+1);
}

void freeTree(binTree *tree)
{
        if (*tree == NULL)
                return;
        freeTree(&(*tree)->left);
        freeTree(&(*tree)->right);
        free(*tree);
}
