#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char arr[], int i, int j) {
    char temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return;
}
void reverse(char *str) {
    for(int i = 0; i < strlen(str) / 2; i++){
        swap(str, i, strlen(str)-i-1);
    }
    return;
}

char *decimal_to_octal(int n) {
    int len=0;
    char str[128];

    while(n>0) {
        str[len++] = n % 8 + '0';
        n = n / 8;
    }
    str[len] = '\0';
    char *return_str = (char *) malloc(sizeof(char)*len);
    strcpy(return_str, str);
    reverse(return_str);
    return return_str;
}

char *decimal_to_hex(int n) {
    int len = 0;
    char str[128];
    char *return_str;
    char large_digits[] = { 'A', 'B', 'C', 'D', 'E', 'F'};
    while(n>0) {
        int remainder = n%16;
        str[len++] = remainder>9 ? large_digits[remainder-10] : remainder + '0';
        n /= 16;
    }
    str[len] = '\0';
    return_str = (char *) malloc(sizeof(char)*len);
    strcpy(return_str, str);
    reverse(return_str);
    return return_str;
}

int main() {
    int n;
    char *octal, *hex;
    printf("Enter number: ");
    scanf("%d", &n);
    octal = decimal_to_octal(n);
    hex = decimal_to_hex(n);
    printf("Decimal: %d\nOctal: %s\nHexadecimal: %s\n", n, octal, hex);
    return 0;
}