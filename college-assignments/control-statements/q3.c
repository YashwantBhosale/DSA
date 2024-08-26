#include <stdio.h>

int count_vowels(char *str) {
    int i = 0, count = 0;
    while(str[i] != '\0') {
        if(str[i] == 'a' || str[i] == 'A' || str[i] == 'e' || str[i] == 'E' || str[i] == 'i' || str[i] == 'I' || str[i] == 'o' || str[i] == 'O' || str[i] == 'u' || str[i] == 'U') {
            count++;
        }
        i++;
    }
    return count;
}
void read_string(char *str, int maxlen) {
    int i = 0;
    while(((str[i] = getchar()) != EOF && str[i] != '\n') && i < maxlen-1)
        i++;
    str[i] = '\0';
    return;
}

int main() {
    char str[64];
    printf("Enter string: ");
    read_string(str, 64);
    printf("No. of vowels = %d\n", count_vowels(str));
    return 0;
}