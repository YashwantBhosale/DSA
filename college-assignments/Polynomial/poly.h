typedef struct {
    int c;
    int e;
} term;

typedef struct  {
    int deg;
    term *t;
} polynomial;

void init_p(polynomial *p, int n);
void append(polynomial *p, int c, int e);
void display(polynomial p);
polynomial *add(polynomial *p1, polynomial *p2);
polynomial *sub(polynomial *p1, polynomial *p2);
// helper functions
void sort(polynomial *p);
void swap(term *arr, int i, int j);