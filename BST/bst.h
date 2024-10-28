#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *lchild, *rchild, *parent;
    int month;
} node;

typedef struct {
    node *root;
    int count;
} bst;

enum Months {
    January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

void init_bst(bst *tree);
void insertNode(bst *tree, int month);
void removeNode(bst *tree, int month);
void inorder(bst *tree);
void destroyTree(bst *tree);

