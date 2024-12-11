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

// Function to read strings including white space character
void read_string(char *str) {
    int i = 0;
    while((str[i] = getchar()) != '\n' && str[i] != '\0' && str[i] != EOF) // EOF because we will be reading a file of testcases
        i++;
    str[i] = '\0';
    return;
}

int main() {
    char str[64];
    while(1){
        printf("Enter string or 'exit' to Exit: \n");
        read_string(str);
        if(strcmp(str, "exit") == 0)
            break;
        printf("Entered string: %s\n", str);
        reverse(str);
        printf("After reversing: %s\n", str);
        printf("\n");
    }
    return 0;
}
