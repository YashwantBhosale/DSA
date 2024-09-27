#include <stdio.h>
#include <stdlib.h>
#include "two_stack.h"

/* 
 *
 *
 *IMPLEMENTATION OF TWOSTACK MUST BE SPACE EFFICEINT
 *
 * */

int main() {
    stack s;
    int size = 5;
    init_stack(&s, size);

    push1(&s, 10);
    push1(&s, 20);
    printf("Stack 1: ");
    print_stack_1(s);

    push2(&s, 30);
    push2(&s, 40);
    printf("Stack 2: ");
    print_stack_2(s);

    printf("popping from stack 2 : %d\n", pop2(&s));
    print_stack_2(s);
    free(s.arr);
    return 0;
}


