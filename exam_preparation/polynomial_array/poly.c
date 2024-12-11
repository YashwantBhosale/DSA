#include <stdio.h>
#include <stdlib.h>
#include "poly.h"

void init_arr(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        arr[i] = 0;
    }
    return;
}

void init_p(polynomial *p, int n) {
    p -> c = (int *) malloc(sizeof(int) * (n+1));
    p -> deg = n;
    init_arr(p->c, n);
    return;
}

void append(polynomial *p, int c, int e) {
    p->c[p->deg-e] = c;
    return;
}

void display(polynomial p) {
    for (int i = 0; i <= p.deg; i++) {
        if(i >= 1 && p.c[i] > 0)
            printf(" +");
        if(p.c[i])
            printf("%dX^%d", p.c[i], p.deg-i);
    }
    printf("\n");
    return;
}

polynomial *add(polynomial *p1, polynomial *p2) {
    int max_deg = p1->deg > p2->deg ? p1->deg : p2->deg;
    polynomial *p3 = (polynomial *)malloc(sizeof(polynomial));
    init_p(p3, max_deg);
    for(int i = 0; i<=max_deg; i++) {
        if(i <= p1->deg && i <= p2->deg) 
            p3->c[max_deg-i] = p1->c[p1->deg - i] + p2->c[p2->deg - i];
        
        else if(i <= p1->deg)
            p3->c[max_deg-i] = p1->c[p1->deg - i];

        else if(i <= p2->deg)
            p3->c[max_deg-i] = p2->c[p2->deg - i];
    }
    return p3;
}


polynomial *sub(polynomial *p1, polynomial *p2) {
    int max_deg = p1->deg > p2->deg ? p1->deg : p2->deg;
    polynomial *p3 = (polynomial *)malloc(sizeof(polynomial));
    init_p(p3, max_deg);
    for(int i = 0; i<=max_deg; i++) {
        if(i <= p1->deg && i <= p2->deg) 
            p3->c[max_deg-i] = p1->c[p1->deg - i] - p2->c[p2->deg - i];
        
        else if(i <= p1->deg)
            p3->c[max_deg-i] = p1->c[p1->deg - i];

        else if(i <= p2->deg)
            p3->c[max_deg-i] = -p2->c[p2->deg - i];
    }
    return p3;
}
