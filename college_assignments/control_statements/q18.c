#include <stdio.h>
#include <math.h>

float calc_wci(float v, float t) {
    if(v >= 0 && v <=4) {
        return t;
    }
    else if(v >= 45){
        return 1.6 * t - 55;
    }
    else {
        float result = 91.4 + (91.4 - t) * (0.0203 * v - 0.304 * sqrt(v) - 0.474);
        return result;
    }
}

int main() {
    float v,t;
    printf("Enter wind speed (in miles per hour) : ");
    scanf("%f", &v);
    printf("Enter Temperature in fahrenheit: ");
    scanf("%f", &t);

    printf("Wind chill index = %f\n", calc_wci(v, t));
    return 0;
}