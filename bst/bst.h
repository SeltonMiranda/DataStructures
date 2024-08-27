#ifndef BST_H
#define BST_H

typedef struct node *Node; 
typedef struct node {
    int key;
    Node parent;
    Node left;
    Node right;
} node;

typedef Node BST;

// Finds a node with the specified key. Return NULL if the tree doesn't contain the key.x
Node tSearch(BST *t, int key);

// Returns node with the least key
Node tMin(BST *t);

// Returns node with the greatest key
Node tMax(BST *t);

// Returns the successor of its node
Node tSuccessor(Node n);

// Returns the predecessor of its node
Node tPredecessor(Node n);

// Inserts a node in BST tree
void tInsert(BST *t, int key);

// In order path
void inOrder(BST *t);

// Deletes node z from tree
void tDelete(BST *t, Node z);

// Dealocate tree
void tFree(BST *t);
#endif // BST_H
