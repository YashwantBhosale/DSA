#include <stdio.h>

int gcd(int a, int b) {
    int gcd=0;
    for(int i = 1; i<=a && i<=b; i++) {
        if(a%i == 0 && b%i == 0) {
            gcd = i;
        }
    }
    return gcd;
}

int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);
    printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));
    return 0;
}