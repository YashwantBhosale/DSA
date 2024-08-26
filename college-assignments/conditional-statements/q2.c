#include <stdio.h>

int check_sign(int n) {
    if(n < 0)
        return -1;
    else if(n > 0)
        return 1;
    else 
     return 0;
}

int main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);

    if(check_sign(n) == 1) {
        printf("Positive number.\n");
    }else if(check_sign(n) == -1) {
        printf("Negative number.\n");
    }else {
        printf("Zero.\n");
    }
    
    return 0;
}