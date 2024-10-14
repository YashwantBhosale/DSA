#include <stdio.h>

double mypow(float x, int n) {
    double result = 1;
    short int sign = 0;
    if(n < 0) {
        sign = 1;
        n = -n;
    }
    for(int i = 0; i < n; i++) {
        result *= x;
    }
    if(sign)
        return 1/result;
    else
        return result;
}

int main() {
    float x;
    int n;
    printf("Enter x and n: ");
    scanf("%f%d", &x, &n);
    
    printf("(x,n) = %lf\n", mypow(x,n));
    return 0;
}
