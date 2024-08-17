#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *cutonchar(char *str, char ch) {
    char str_buffer[64];
    int i = 0;
    while(str[i] != ch && str[i] != '\0') {
        str_buffer[i] = str[i];
        i++;
    }
    if(str[i] == ch) {
	str_buffer[i++] = ch;
	str_buffer[i] = '\0';
        char *return_str = (char *) malloc(sizeof(char) * i);
        strcpy(return_str, str_buffer);
        return return_str;
    }
    return NULL;
}

int main() {
    char str[] = "something";
    printf("%s\n", cutonchar(str, 'e'));
    return 0;
}
