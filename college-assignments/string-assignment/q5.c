#include <stdio.h>
#include <stdlib.h>

int lcm(int num1, int num2) {
    for(int i = 1; i <= num1*num2; i++) {
        if(i%num1 == 0 && i%num2 == 0) {
            return i;
        }
    }
    return num1*num2;
}

int main(){
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    printf("LCM of %d and %d is %d\n", num1, num2, lcm(num1, num2));
    return 0;
}
