// Write a function to count number of occurrences of a character in a string.
#include <stdio.h>
#include <string.h>

int count_occurrence(char str[], char c) {
    int count = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == c)
            count++;
    }
    return count;
}

int main() {
    char string[64];
    strcpy(string, "hello");
    printf("Occurence of 'l' in %s: %d\n", string, count_occurrence(string, 'l'));
    return 0;
}