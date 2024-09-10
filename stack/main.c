#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    stack s;
    init(&s, 10);
    push(&s, 10);
    push(&s,12);
    display(s);
    printf("Peeking stack: %d\n", peek(s));
    printf("Popping element: %d\n", pop(&s));
    display(s);
    return 0;
}