#include <stdio.h>
#include <math.h>
float simple_interest(float p, float n, float r) {
    return (p * n * r) / 100;
}

float compound_interest(float p, float n, float r) {
    float result = p * pow((100 + r) / 100, n) - p;
    return result;
}

int main() {
    float p,r,t;

    printf("Enter principal amount: ");
    scanf("%f", &p);

    printf("Enter rate (per annum): ");
    scanf("%f", &r);

    printf("Enter time (years): ");
    scanf("%f", &t);

    printf("Simple interest = %f\n", simple_interest(p,t,r));
    printf("Compound interest = %f\n", compound_interest(p,t,r));
    return 0;
}