#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *str) {
    int len = strlen(str);
    char *p = str;
    char *q = str + len - 1;

    for (int i = 0; i < len / 2; i++) {
        char c = *p;
        *p = *q;
        *q = c;
        p++;
        q--;
    }
}
char *decimal_to_binary(int n) {
    char *str = (char *)malloc(sizeof(char) * 64);
    int i = 0;
    while (n > 0) {
        str[i] = n % 2 + '0';
        n = n / 2;
        i++;
    }
    str[i] = '\0';
    reverse(str);
    return str;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Decimal string: %s\n", decimal_to_binary(n));
    return 0;
}