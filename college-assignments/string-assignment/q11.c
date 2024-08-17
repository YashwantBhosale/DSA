#include <stdio.h>
#include <math.h>

int reverse_int(int n) {
    int sign_flag = 0;
    if(n<0){
        n = -n;
        sign_flag = 1;
    }
    int reverse = 0;
    while(n > 0) {
        reverse = reverse * 10 + n%10;
        n /= 10;
    }
    return sign_flag ? reverse * (-1) : reverse;
}

int main() {
    int n, reversed;
    printf("Enter a number: ");
    scanf("%d", &n);
    reversed = reverse_int(n); 
    printf("Reversed number: %d\n", reversed);
    return 0;
}
