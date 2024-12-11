#include <stdio.h>

void print_odd(int m, int n) {
    int large, small;
    if(m>n) {
        large = m;
        small = n;
    }else {
        large = n;
        small = m;
    }
    for(int i = small; i <= large;i++) {
        if(i%2){
            printf("%d\t", i);
        }
    }
    return;
}

int main() {
    int m, n;
    printf("Enter m and n: ");
    scanf("%d%d", &m, &n);
    print_odd(m, n);
    return 0;
}