#include <stdio.h>

int is_prime(int n) {
    if(n == 1)
        return 0;
    for(int i = 2; i < n; i++) {
        if((n%i) == 0)
            return 0;
    }
    return n;
}

void print_prime(int m, int n) {
    int large, small;
    if(m>n) {
        large = m;
        small = n;
    }else {
        large = n;
        small = m;
    }
    for(int i = small; i <= large; i++) {
        if(is_prime(i)) {
            printf("%d\t", i);
        }
    }
    return;
}

int main() {
    int m, n;
    printf("Enter m and n: ");
    scanf("%d%d", &m, &n);
    print_prime(m, n);
    return 0;
}