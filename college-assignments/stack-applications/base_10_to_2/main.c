#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

char *to_binary(int num) {
    // Maximum length that the binary representation string of a decimal number can have is [n/2] or floor(n/2).
    int len = num <= 1 ? 2 : ((num/2)+1); // +1 for null character
    int i, top; 
    char *result = (char *) malloc(sizeof(char) * len);
    stack bin_stack;
    init_stack(&bin_stack, len);
    while(num) {
        push(&bin_stack, (num%2+'0'));
        num = num/2;
    }
    top = bin_stack.top;
    for(i = 0; i <= top; i++) {
        result[i] = pop(&bin_stack);
    }
    result[i] = '\0';
    return result;
}

int main() {
    int num;
    char *bin = NULL;
    printf("Enter Number: ");
    scanf("%d", &num);
    if(num >= 0){
        bin = to_binary(num);
        printf("Binary: %s\n", bin);
        free(bin);
    }
    return 0;
}
