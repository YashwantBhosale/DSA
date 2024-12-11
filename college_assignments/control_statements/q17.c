#include <stdio.h>

int is_armstrong(int n) {
    int cube_sum = 0, total = n;
    while(n) {
        int r = n%10;
        cube_sum += r*r*r;
        n/=10;
    }
    return cube_sum == total;
}

int main() {
    int n;
    scanf("%d", &n);

    while(n != -1) {
        if(is_armstrong(n)){
            printf("Entered number is armstrong number.\n");
        }else {
            printf("Entered number is NOT armstrong number.\n");
        }
        scanf("%d", &n);
    }

    return 0;
}