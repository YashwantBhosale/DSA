// Write a C program to input any alphabet and check whether it is vowel or consonant.
#include <stdio.h>

int main() {
    char a;
    printf("Enter an alphabet: ");
    a = getchar();
    if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U') {
        printf("Entered character is a vowel\n");
    }else {
        printf("Entered character is a consonant\n");
    }
    return 0;
}