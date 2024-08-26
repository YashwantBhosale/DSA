#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int no_of_digits(int n) {
    int count=0;
    while(n) {
        n/=10;
        count++;
    }
    return count;
}

void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

char *exp_format(float f, int precision) {
    int exp=0, i=0, j=2;
    char str[64];
    char *return_str;

    float fraction = f - (int) f;
    fraction *= 10;
    while(fraction - (int) fraction) {
        str[i++] = ((int) fraction)%10 + '0';
        fraction *= 10;
    }
    str[i++] = ((int)fraction)%10 + '0';
    str[i] = '\0';
    reverse(str);
    while(f >= 10 || f <= -10) {
        str[i++] = ((int)f)%10 + '0';
        f = f/10;
        exp++;
    }
    i--;
    return_str = (char *) malloc((precision + 5 + no_of_digits(exp)) *sizeof(char)); // 2 (msb and '.') + precision + 4 (e, "+", ..., <no of digits>) + null byte
    return_str[0] = ((int)f) % 10 + '0';
    return_str[1] = '.';
    while(precision) {
        return_str[j] = i >= 0 ? str[i] : '0';
        j++;
        i--;
        precision--;
    }
    return_str[j] = '\0';
    return_str[j++] = 'e';
    return_str[j++] = '+';
    if(exp<10)
        return_str[j++] = '0';
    while(exp>=10){
        return_str[j++] = exp/10 + '0';
        exp/=10;
    }
    return_str[j++] = exp + '0';
    return return_str;
}

int main() {
    float f;
    printf("Enter floating point number: ");
    scanf("%f", &f);
    printf("a. correct to two decimal places: %s\n", exp_format(f, 2));
    printf("b. correct to four decimal places: %s\n", exp_format(f, 4));
    printf("c. correct to eight decimal places: %s\n", exp_format(f, 8));
    return 0;
}