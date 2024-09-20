#include <stdio.h>
#include <stdlib.h>
#include "poly.h"

// Function prototypes
polynomial* add(polynomial *p1, polynomial *p2);
polynomial* sub(polynomial *p1, polynomial *p2);

int main() {
    // Test Case 1: Adding two polynomials
    polynomial p1, p2, *sum, *difference;

    // Initialize polynomials p1 and p2
    init_p(&p1, 3); // p1: 0x^3 + 0x^2 + 0x^1 + 0x^0
    init_p(&p2, 2); // p2: 0x^2 + 0x^1 + 0x^0

    // Append coefficients to polynomials
    append(&p1, 1, 3); // p1: x^3
    append(&p1, 2, 2); // p1: x^3 + 2x^2
    append(&p1, 3, 1); // p1: x^3 + 2x^2 + 3x^1
    append(&p1, 4, 0); // p1: x^3 + 2x^2 + 3x^1 + 4

    append(&p2, 5, 2); // p2: 5x^2
    append(&p2, -3, 1); // p2: 5x^2 - 3x^1
    append(&p2, 7, 0); // p2: 5x^2 - 3x^1 + 7

    // Display input polynomials
    printf("Polynomial 1: ");
    display(p1); // Expected: x^3 + 2x^2 + 3x + 4
    printf("Polynomial 2: ");
    display(p2); // Expected: 5x^2 - 3x + 7

    // Test addition of p1 and p2
    sum = add(&p1, &p2);
    printf("Sum: ");
    display(*sum); // Expected: x^3 + 7x^2 + 0x + 11

    // Test subtraction of p1 and p2
    difference = sub(&p1, &p2);
    printf("Difference: ");
    display(*difference); // Expected: x^3 - 3x^2 + 6x - 3

    // Free allocated memory
    free(p1.c);
    free(p2.c);
    free(sum->c);
    free(difference->c);
    free(sum);
    free(difference);

    // Test Case 2: Adding and subtracting polynomials with different degrees
    polynomial p3, p4;

    init_p(&p3, 4); // p3: 0x^4 + 0x^3 + 0x^2 + 0x^1 + 0x^0
    init_p(&p4, 2); // p4: 0x^2 + 0x^1 + 0x^0

    append(&p3, 2, 4); // p3: 2x^4
    append(&p3, -1, 1); // p3: 2x^4 - x^1
    append(&p3, 3, 0); // p3: 2x^4 - x + 3

    append(&p4, 1, 2); // p4: x^2
    append(&p4, 4, 0); // p4: x^2 + 4

    printf("\nPolynomial 3: ");
    display(p3); // Expected: 2x^4 - x + 3
    printf("Polynomial 4: ");
    display(p4); // Expected: x^2 + 4

    sum = add(&p3, &p4);
    printf("Sum of Polynomial 3 and Polynomial 4: ");
    display(*sum); // Expected: 2x^4 + x^2 - x + 7

    difference = sub(&p3, &p4);
    printf("Difference of Polynomial 3 and Polynomial 4: ");
    display(*difference); // Expected: 2x^4 - x^2 - x - 1

    // Free allocated memory
    free(p3.c);
    free(p4.c);
    free(sum->c);
    free(difference->c);
    free(sum);
    free(difference);

    return 0;
}
