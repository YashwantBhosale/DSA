// Write a c program to check whether a character is lower case or upper case.
#include <stdio.h>
int main() {    
    char a;
    a = getchar();
    if(a >= 'a' && a <= 'z') {
        printf("You entered lower case character.\n");
    }else if(a >= 'A' && a <= 'Z') {
        printf("You enetered upper case character.\n");
    }else{
        printf("you entered invalid alphabet.\n");
    }
    return 0;
}