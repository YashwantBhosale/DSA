// Write a C program to check whether a character is alphabet or not.
#include <stdio.h>

int main() {
    char a;
    a = getchar();
    if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')) {
        printf("You entered an alphabet.\n");
    }else {
        printf("You entered a non-alphabet character.\n");
    }
    return 0;
}