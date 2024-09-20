typedef struct term{
    int c;
    int e;
    struct term *next;
} term;

typedef term * polynomial;

void init_p(polynomial *p);
void append(polynomial *p, int c, int e);
void display(polynomial p);
polynomial add(polynomial p1, polynomial p2);
polynomial sub(polynomial p1, polynomial p2);
