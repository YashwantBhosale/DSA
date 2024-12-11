#include <stdio.h>

int is_number(char c){
    return c >= '0' && c <= '9';
}

int is_char(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int is_upperCase(char c) {
    return c >= 'A' && c <= 'Z';
}

int main() {
    char c;
    c = getchar();
    if(is_number(c)) {
        printf("It is a number\n");
    }else if(is_char(c)) {
        is_upperCase(c) ?
        printf("It is a Uppercase character\n") :
        printf("It is a lowercase character.\n");

        printf("ascii = %d\n", c);
    }else{
        printf("Invalid input!\n");
    }

    return 0;
}