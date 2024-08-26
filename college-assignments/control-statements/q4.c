#include <stdio.h>

int main() {
    float f1, f2;
    int sum; 
    printf("Enter two floating point numbers: ");
    scanf("%f%f", &f1, &f2);

    sum = f1 + f2;
    printf("sum of %f and %f as an integer is %d\n", f1, f2, sum);
    return 0;
}