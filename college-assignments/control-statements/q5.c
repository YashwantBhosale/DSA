#include <stdio.h>
int main() {
    float f;
    int i;
    printf("Enter a floating point number: ");
    scanf("%f", &f);
    i = (int) f;
    printf("Rightmost digit of integer part = %d\n", i%10);
    return 0;
}