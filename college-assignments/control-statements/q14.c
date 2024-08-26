#include <stdio.h>

int sum(int n) {
    int sum = 0;
    for(int i = 1; i <= n; i++) 
        sum+=i;
    return sum;
}

float average(int n) {
    return ((float)sum(n) / (float)n);
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Sum = %d\nAverage = %f\n", sum(n), average(n));
    return 0;
}