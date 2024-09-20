#include <stdio.h>
#include <stdlib.h>
#include "poly.h"

void init_p(polynomial *p) {
    *p = NULL;
    return;
}
void append(polynomial *p, int c, int e) {
    term *t = (term *) malloc(sizeof(term));
    t->c = c;
    t->e = e;
    if(*p==NULL) {
        *p = t;
        t->next = NULL;
        return;
    }
    
    if(e > (*p)->e) {
        t->next = *p;
        *p = t;
        return;
    }

    term *current = *p;
    term *prev = NULL;

    while(current && current->e>=e) {
        if(current->e == e) {
            current -> c += c;
            free(t);
            return;
        }

        prev = current;
        current = current->next;
    }
    if(prev){
        t->next = current;
        prev->next = t;
    }

    return;
}   

polynomial add(polynomial p1, polynomial p2) {
    polynomial p3 = NULL; // Initialize p3 to NULL
    term *p = p1, *q = p2;

    while (p != NULL && q != NULL) {
        // Case 1: Exponents are equal
        if (p->e == q->e) {
            append(&p3, p->c + q->c, p->e); // Combine coefficients
            p = p->next;
            q = q->next;
        }
        // Case 2: Exponent of p is greater
        else if (p->e > q->e) {
            append(&p3, p->c, p->e);
            p = p->next;
        }
        // Case 3: Exponent of q is greater
        else {
            append(&p3, q->c, q->e);
            q = q->next;
        }
    }

    // Append remaining terms from p1
    while (p != NULL) {
        append(&p3, p->c, p->e);
        p = p->next;
    }

    // Append remaining terms from p2
    while (q != NULL) {
        append(&p3, q->c, q->e);
        q = q->next;
    }

    return p3;
}

polynomial sub(polynomial p1, polynomial p2) {
    polynomial p3 = NULL; // Initialize p3 to NULL
    term *p = p1, *q = p2;

    while (p != NULL && q != NULL) {
        // Case 1: Exponents are equal
        if (p->e == q->e) {
            append(&p3, p->c - q->c, p->e); // Combine coefficients
            p = p->next;
            q = q->next;
        }
        // Case 2: Exponent of p is greater
        else if (p->e > q->e) {
            append(&p3, p->c, p->e);
            p = p->next;
        }
        // Case 3: Exponent of q is greater
        else {
            append(&p3, -q->c, q->e);
            q = q->next;
        }
    }

    // Append remaining terms from p1
    while (p != NULL) {
        append(&p3, p->c, p->e);
        p = p->next;
    }

    // Append remaining terms from p2
    while (q != NULL) {
        append(&p3, -q->c, q->e);
        q = q->next;
    }

    return p3;
}


void display(polynomial p) {
    term *t = p;
    while(t) {
        if(t!=p && t->c>0)
            printf("+");
        printf("%dX^%d ", t->c, t->e);
        t = t->next;
    }
    printf("\n");
    return;
}