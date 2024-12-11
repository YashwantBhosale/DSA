#include <stdio.h>
#include <string.h>

char *str_tok(char *str, char *delim) {
    static char *ptr = NULL;
    if (str) ptr = str;
    if (ptr == NULL) return NULL;
    char *start = ptr;
    char *p = ptr;
    while (*p != '\0' && *p != *delim) p++;
    if (*p == '\0') {
        ptr = NULL;
    } else {
        *p = '\0';
        ptr = ++p;
    }
    return start;
}

int main() {
    char string[64];
    char *token;
    strcpy(string, "yashwant,chandrakant,bhosale, 1234");

    token = str_tok(string, ",");

    while (token != NULL) {
        printf("%s\n", token);
        token = str_tok(NULL, ",");
    }

    return 0;
}