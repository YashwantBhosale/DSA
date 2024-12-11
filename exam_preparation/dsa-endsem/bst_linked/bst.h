typedef struct node {
    int data;
    struct node *lchild, *rchild;
} Node;

typedef node *BST;

void init_bst(BST *bst);
void insert(BST *bst, int data);
void remove(BST *bst, int data);
void destroy(BST *bst);

