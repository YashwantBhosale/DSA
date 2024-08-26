#include <stdio.h>
#define HRA 10
#define TA 5

int main() {
    float salary;
    printf("Enter salary : ");
    scanf("%f", &salary);

    printf("HRA = %f\nTA = %f\n", (salary*HRA)/100, (salary*TA)/100);
    return 0;
}