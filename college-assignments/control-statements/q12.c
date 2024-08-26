#include <stdio.h>

int main() {
    float f1, f2, f3, sum;
    
    printf("Enter three floating point numbers: ");
    scanf("%f%f%f", &f1, &f2, &f3);

    sum = f1 + f2 + f3;
    sum *= 100;
    sum = (int)sum;
    sum = sum / 100;

    printf("sum = %f\n", sum);
    return 0;
}