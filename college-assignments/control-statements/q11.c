#include <stdio.h>

int main() {
    char c;
    printf("Enter character: ");
    while((c = getchar()) != '*') {
        if(c >= 'a' && c <='z') {
            printf("%c, ascii= %d\nEnter character: ", c - ('a' - 'A'), c);
        }else if(c >= 'A' && c <= 'Z'){
            printf("%c, ascii = %d\nEnter character: ", c + ('a' - 'A'), c);
        }
    }

    return 0;
}