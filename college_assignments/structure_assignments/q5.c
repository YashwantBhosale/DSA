#include <stdio.h>
#include <stdlib.h>

typedef struct fraction {
	float numerator;
	float denominator;
}fraction;

int compare(fraction f1, fraction f2) {
	float fraction_1 = f1.numerator / f1.denominator;
	float fraction_2 = f2.numerator / f2.denominator;
	
	if(fraction_1 > fraction_2)
		return 1;
	else if(fraction_1 < fraction_2)
		return 0;
	else
		return -1;
	
} 


int main() {
	fraction f1, f2;
	printf("Enter first fraction: \n");
	printf("Numerator : ");
	scanf("%f", &f1.numerator);
	printf("Denominator : ");
	scanf("%f", &f1.denominator);
	while(f1.denominator == 0) {
		printf("invalid denominator!\nDenominator: ");	
		scanf("%f", &f1.denominator);
	}

	printf("Enter second fraction: \n");	
	printf("Numerator : ");
	scanf("%f", &f2.numerator);
	printf("Denominator : ");
	scanf("%f", &f2.denominator);
	
	while(f2.denominator == 0) {
		printf("invalid denominator!\nDenominator: ");	
		scanf("%f", &f2.denominator);
	}

	int result  = compare(f1, f2);

	if(!result) 
		printf("Second fraction is greater than the first.\n");
	else if(result == 1)
		printf("First fraction is greater than the second.\n");
	else
		printf("Both fractions are equal.\n");
		
	return 0;
}
