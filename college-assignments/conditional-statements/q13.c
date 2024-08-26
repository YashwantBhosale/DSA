// write a c program to find all roots of quadratic equation.

#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c, D, x1, x2;
    printf("Enter coefficients: \n");
    scanf("%d%d%d", &a, &b, &c);

    D = b*b - 4*a*c;

    if(D >= 0){
        x1 = (-b + sqrt(D)) / (2*a); 
        x2 = (-b - sqrt(D)) / (2*a);
        printf("x1: %d, x2: %d\n", x1, x2);
    }else {
        printf("Roots are not real.\n");
    }

    return 0;
}