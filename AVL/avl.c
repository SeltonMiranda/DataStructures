#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

// Creates a new node
static ApNodo createNode(int key)
{
    ApNodo new = (ApNodo)malloc(sizeof(Nodo));
    if (new == NULL) exit(1);
    new->parent = NULL;
    new->left = NULL;
    new->right = NULL;
    new->key = key;
    return new;
}

// Returns the height of current node, -1 if tree is empty
static int avl_height(AVL *t)
{
    if ((*t) == NULL) return -1;
    int left_height = avl_height(&(*t)->left);
    int right_height = avl_height(&(*t)->right);
    if (left_height > right_height) return left_height + 1;
    return right_height + 1;
}

// Returns the node with greatest key 
static ApNodo avl_max(ApNodo nodo)
{
    while (nodo->right != NULL) nodo = nodo->right;
    return nodo;
}

// Rotate left
static AVL avl_rotation_left(AVL *t)
{
    ApNodo q = (*t)->right;

    (*t)->right = q->left;
    q->parent = (*t)->parent;
    (*t)->parent = q;

    if (q->left != NULL) q->left->parent = (*t);
    q->left = (*t);

    q->height = avl_height(&q);
    (*t)->height = avl_height(&(*t));

    return q;
}

// Rotate right
static AVL avl_rotation_right(AVL *t)
{
    ApNodo q = (*t)->left;
    (*t)->left = q->right;
    q->parent = (*t)->parent;
    (*t)->parent = q;

    if (q->right != NULL) q->right->parent = (*t);
    q->right = (*t);

    q->height = avl_height(&q);
    (*t)->height = avl_height(&(*t));

    return q;
}

// Balance factor of current node
static int avl_balance_factor(AVL *t)
{
    if ((*t) == NULL) return 0;
    return (avl_height(&(*t)->left) - avl_height(&(*t)->right));
}

// Rebalance the tree according to its balance factor node
static AVL avl_balance(AVL *t)
{
    // Simple left rotation
    if (avl_balance_factor(&(*t)) < -1 && avl_balance_factor(&(*t)->right) <= 0) {
        return avl_rotation_left(&(*t));
    }

    if (avl_balance_factor(&(*t)) > 1 && avl_balance_factor(&(*t)->left) >= 0) {
        return avl_rotation_right(&(*t));
    }

    if (avl_balance_factor(&(*t)) > 1 && avl_balance_factor(&(*t)->left) < 0) {
        (*t)->left = avl_rotation_left(&(*t)->left);
        return avl_rotation_right(&(*t));
    }

    if (avl_balance_factor(&(*t)) < -1 && avl_balance_factor(&(*t)->right) > 0) {
        (*t)->right = avl_rotation_right(&(*t)->right);
        return avl_rotation_left(&(*t));
    }

    return *t;
}

AVL avl_insert(AVL *t, int key)
{
    if ((*t) == NULL) return createNode(key);
    if (key < (*t)->key) {
        (*t)->left = avl_insert(&(*t)->left, key);
        (*t)->left->parent = *t;
    } else {
        (*t)->right = avl_insert(&(*t)->right, key);
        (*t)->right->parent = *t;
    }

    (*t)->height = avl_height(&(*t));
    *t = avl_balance(&(*t));
    return *t;
}
 
AVL avl_delete(AVL *t, int key) {
    if (*t == NULL) 
        return NULL;

    if (key < (*t)->key) {
        (*t)->left = avl_delete(&(*t)->left, key);
    } else if (key > (*t)->key) {
        (*t)->right = avl_delete(&(*t)->right, key);
    } else {
        // Case 1: Node is leaf
        if ((*t)->left == NULL && (*t)->right == NULL) {
            free(*t);
            return NULL;
        }

        // Case 2: Node has 1 child
        else if ((*t)->left == NULL || (*t)->right == NULL) {
            ApNodo temp = (*t)->left ? (*t)->left : (*t)->right;

            // If the node isn't root, update parent
            if ((*t)->parent != NULL) {
                if ((*t)->parent->left == *t) 
                    (*t)->parent->left = temp;
                else 
                    (*t)->parent->right = temp;
            }
            if (temp != NULL) temp->parent = (*t)->parent;
            free(*t);
            return temp;
        }

        // Case 3: Node has 2 children
        else {
            ApNodo predecessor = avl_max((*t)->left); 
            (*t)->key = predecessor->key; 
            (*t)->left = avl_delete(&(*t)->left, predecessor->key);
        } 
    }
    (*t)->height = avl_height(&(*t));
    *t = avl_balance(&(*t));
    return *t;
}

void inOrder(AVL *t)
{
    if ((*t) == NULL) return;
    inOrder(&(*t)->left);
    printf("%d ", (*t)->key);
    inOrder(&(*t)->right);
}

void avl_free(AVL *t)
{
    if ((*t) == NULL) return;
    avl_free(&(*t)->left);
    avl_free(&(*t)->right);
    free(*t);
}
