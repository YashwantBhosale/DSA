#include <stdio.h>
#include <string.h>

 

int main() {
    char string[64];
    char *token;
    strcpy(string, "hello,world");

    // Get the first token
    token = str_tok(string, ",");

    // Print each token
    while (token != NULL) {
        printf("%s\n", token);
        token = str_tok(NULL, ",");
    }

    return 0;
}