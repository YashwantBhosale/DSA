#include <stdio.h>

int is_divisible_by_n(int number, int n) { return !(number % n); }

// Logical Exclusive or
int xor (int a, int b) { return (a && !b) || (!a && b); }

    int main() {
    int number;
    printf("Enter number : ");
    scanf("%d", &number);

    printf("Is 10 divisible by 5 and 6? : %s\n",
           is_divisible_by_n(number, 5) && is_divisible_by_n(number, 6)
               ? "True"
               : "False");
    printf("Is 10 divisible by 5 or 6? : %s\n",
           is_divisible_by_n(number, 5) || is_divisible_by_n(number, 6)
               ? "True"
               : "False");
    printf("Is 10 divisible by 5 or 6, but not both? : %s\n",
           xor(is_divisible_by_n(number, 5), is_divisible_by_n(number, 6))
               ? "True"
               : "False");

    return 0;
}