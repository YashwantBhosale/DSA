// Write a c program to check whether the triangle is equilateral, isoscales or scalene triangle.

#include <stdio.h>

int main() {
    int side1, side2, side3;
    scanf("%d%d%d", &side1, &side2, &side3);

    if(side1 == side2 && side2 == side3) printf("Equilateral triangle\n");
    else if(side1 != side2 && side2 != side3 && side1 != side3) printf("Scalene Triangle\n");
    else printf("Isoscales triangle\n");
    return 0;
}