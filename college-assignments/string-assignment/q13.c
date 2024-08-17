#include <stdio.h>
#include <string.h>
void rev(char *str) {
    for(int i = 0; i < strlen(str)/2; i++){
        str[i] = str[i] + str[strlen(str) - i - 1];
        str[strlen(str) - i - 1] = str[i] - str[strlen(str) - i - 1];
        str[i] -= str[strlen(str) - i - 1];
    }
    return;
}

int main() {
    char str[128];
    printf("Enter a string : ");
    scanf("%s", str);
    rev(str);
    printf("reversed : %s\n", str);
    return 0;
}
