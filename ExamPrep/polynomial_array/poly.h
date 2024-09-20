typedef struct {
    int *c;
    int deg;
} polynomial;

void init_p(polynomial *p, int deg);
void append(polynomial *p, int c, int e);
void display(polynomial p);
polynomial *add(polynomial *p1, polynomial *p2);
polynomial *sub(polynomial *p1, polynomial *p2);
