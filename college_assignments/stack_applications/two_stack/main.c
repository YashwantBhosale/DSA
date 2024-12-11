#include <stdio.h>
#include <stdlib.h>
#include "two_stack.h"

int main() {
    stack s;
    int size = 10;
    init_stack(&s, size);

    push1(&s, 10);
    push1(&s, 20);
    push1(&s, 13);
    push1(&s, 23);
    printf("Stack 1: ");
    print_stack_1(s);
    
    push2(&s, 55);
    push2(&s, 47);
    push2(&s, 30);
    push2(&s, 40);
    printf("Stack 2: ");
    print_stack_2(s);

    printf("popping from stack 2 : %d\n", pop2(&s));
    printf("Stack 2: ");
    print_stack_2(s);
    free(s.arr);
    return 0;
}


