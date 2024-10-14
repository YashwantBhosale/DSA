#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

short int is_opening_paranthesis(char c) {
    return (c=='(' || c=='[' || c=='{');
}

short int is_closing_paranthesis(char c) {
    return (c==')' || c==']' || c=='}');
}

char match(char c) {
    switch(c) {
        case '(':
            return ')';
        case '[':
            return ']';
        case '{':
            return '}';
        default:
            break;
    }
    return 0;
}

short int valid_paranthesis(char *s) {
    int len = strlen(s); 
    
    stack char_stack;
    init_stack(&char_stack, len);
    for(int i = 0;i < len; i++) {
        if(is_opening_paranthesis(s[i]))
            push(&char_stack, s[i]);

        if(is_closing_paranthesis(s[i]) && match(pop(&char_stack)) != s[i])
            return 0;

    }
    if(is_empty(char_stack))
        return 1;
    else
        return 0;
}

int main() {
    char str[64];

    while(1){
        printf("Enter string or enter 'exit' to exit the program: \n");
        scanf("%s", str);
        if(strcmp(str, "exit") == 0)
            break;
        printf("Expression: %s\nResult: ", str);
        if(valid_paranthesis(str))
            printf("True\n");
        else
            printf("False\n");
        
        printf("\n");
    }
    return 0;
}
