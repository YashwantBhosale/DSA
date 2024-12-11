#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

char *to_binary(int num) {
    /* Maximum length that the binary representation string of a decimal number can 	 have is [n/2] or floor(n/2).*/
    int len = num <= 1 ? 2 : ((num/2)+1); // +1 for null character
    int i, top; 
    char *result = (char *) malloc(sizeof(char) * len);
    stack bin_stack;
    init_stack(&bin_stack, len);
    while(num) {
        push(&bin_stack, (num%2+'0')); // push ascii value of digits to string
        num = num/2;
    }
    top = bin_stack.top;
    for(i = 0; i <= top; i++) {
        result[i] = pop(&bin_stack); // pop digits in result string
    }
    result[i] = '\0';
    return result;
}

int main() {
    int num;
    char *bin = NULL;
    while(1){
        printf("Enter Number: ");
        scanf("%d", &num);
        
        printf("Entered number: %d\n", num);

        if(num >= 0){
            bin = to_binary(num);
            printf("Binary: %s\n\n", bin);
            free(bin);
        }else {
            break;
        }
    }
    return 0;
}
