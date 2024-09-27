#include <stdio.h>
#include <string.h>
#include "stack.h"

void reverse(char *s) {
    stack char_stack;
    int len = strlen(s);
    init_stack(&char_stack, len);

    for(int i = 0; i < len; i++)
        push(&char_stack, s[i]);
    for(int j = 0; j < len; j++)
        s[j] = pop(&char_stack);
    return;
}

int main() {
    char str[64];
    printf("Enter string: ");
    scanf("%s", str);
    reverse(str);
    printf("After reversing: %s\n", str);
    return 0;
}
