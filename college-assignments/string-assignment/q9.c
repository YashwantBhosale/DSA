//  Write following functions: sine, sine-inverse, cosine, cosine-inverse. Then using sine and cosine, write tan() function. Check whether calling sine(sine-inverse(x)) on your own functions gives you x.
#include <stdio.h>
#include <math.h>

double sine(double x) {
    double sinex, term;
    int i = 3, sign = -1;
    
    sinex = x;
    term = x;
    while(fabs(term) > 1e-8) {
        term = (term * (x * x)) / (i * (i-1));
        sinex = sinex + (sign * term);
	    sign = sign * (-1);
	    i+=2;    
    }
    return sinex;
}

double cosine(double x) {
    double cosinex, term;
    int i = 2, sign = -1;

    cosinex = 1;
    term = 1;

    while(fabs(term) > 1e-8) {
        term = (term * (x * x)) / (i * (i-1));
        cosinex = cosinex + (sign * term);
        sign = sign * (-1);
        i+=2;
    }
    return cosinex;
}	

double sine_inverse(double x) {
    if(fabs(x) > 1) {
        printf("Invalid Input!\n");
        return 0;
    }
    double sine_inversex, term;
    int i = 0;

    sine_inversex = x;
    term = x;

    while(fabs(term) > 1e-8) {
        term = ((2*i + 1) * (2*i + 1) * (x*x) * term)/((2*i + 2) * (2*i + 3));
        sine_inversex += term;
        i++;
    }
    return sine_inversex;
}

double cosine_inverse(double x) {
    if(fabs(x) > 1) {
        printf("Invalid input!\n");
        return 0;
    }
    return (1.57079632 - sine_inverse(x)); 	
}

int main() {
    double x, result;
    printf("Enter x: ");
    scanf("%lf", &x);
    int option;
    printf("1. Calculate Sinex\n2. Calculate Cosinex\n3. Calculate sine inverse x.\n4. Calculate cosine inverse x.\n5. Calculate tanx.\n");
    printf("Enter option: ");
    scanf("%d", &option);
    switch(option) {
        case 1: {
            result = sine(x);
            break;
        }
        case 2: {
            result = cosine(x);
            break;
        }
        case 3: {
            result = sine_inverse(x);
            break;
        }
        case 4: {
            result = cosine_inverse(x);
            break;
        }
	    case 5: {
	        result = sine(x) / cosine(x);
            break;
	    }
        default: {
            printf("Invalid option!");
            result = -1;
            break;
        }
    }

    printf("result = %lf\n", result);
    return 0;
}
