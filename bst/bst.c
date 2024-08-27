#include "bst.h"
#include <stdlib.h>
#include <stdio.h>


Node tSearch(BST *t, int key)
{
    if (t == NULL || *t == NULL ) return NULL;
    if (key == (*t)->key) return *t;
    if (key < (*t)->key) return tSearch(&(*t)->left, key);
    return tSearch(&(*t)->right, key);
}

Node tMin(BST *t)
{
    Node node = *t;
    while (node->left != NULL) node = node->left; 
    return node;
}

Node tMax(BST *t)
{
    Node node = *t;
    while (node->right != NULL) node = node->right;
    return node;
}

Node tSuccessor(Node n)
{
    if (n == NULL) return NULL;
    if (n->right != NULL) return tMin(&n->right);
    Node y = n->parent;
    while (y != NULL && y->right == n) {
        n = y;
        y = y->parent;
    }
    return y;
}

Node tPredecessor(Node n)
{
    if (n == NULL) return NULL;
    if (n->left != NULL) return tMax(&n->left);
    Node y = n->parent;
    while (y != NULL && y->left == n) {
        n = y;
        y = y->parent;
    }
    return y;
}

static Node tCreateNode(int key)
{
    Node newNode = (Node)malloc(sizeof(node));
    if (newNode == NULL) return NULL;

    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    newNode->key = key;
    return newNode;
}

void tInsert(BST *t, int key)
{
    Node newNode = tCreateNode(key);
    if (newNode == NULL) {
        fprintf(stderr, "Could not allocate memory for Node\n");
        exit(1);
    }

    Node x, y;
    y = NULL;
    x = *t;
    while (x != NULL) {
        y = x;
        if (newNode->key < x->key) x = x->left;
        else x = x->right;
    }

    newNode->parent = y;
    if (y == NULL) *t = newNode;
    else if (newNode->key < y->key) y->left = newNode;
    else y->right = newNode;
}

static void transplant(BST *t, Node u, Node v)
{
    if (u->parent == NULL) (*t) = v;
    else if (u == u->parent->left) u->parent->left = v;
    else u->parent->right = v;

    if (v != NULL) v->parent = u->parent;
}

void tDelete(BST *t, Node z)
{
    if (z == NULL) return;
    if (z->left == NULL) {
        transplant(t, z, z->right);
    } else if (z->right == NULL) {
        transplant(t, z, z->left);
    } else {
        Node y = tMin(&z->right);
        if (y->parent != z) {
            transplant(t, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(t, z, y);
        y->left = z->left;
        y->left->parent = y;
    }
    free(z);
}

void tFree(BST *t)
{
    if (*t == NULL) return;
    tFree(&(*t)->left);
    tFree(&(*t)->right);
    free(*t);
}

void inOrder(BST *t) 
{
    if (*t == NULL) return;
    inOrder(&(*t)->left);
    printf("%d ", (*t)->key);
    inOrder(&(*t)->right);
}
