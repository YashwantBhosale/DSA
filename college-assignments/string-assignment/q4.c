#include <stdio.h>
#include <stdlib.h>

int lcm(int num1, int num2) {
    int sum1 = 0, sum2 = 0;
    while(sum1 <= (num1*num2) && sum2 <= (num1*num2)){
        sum1 += num1;
        sum2 += num2;
        if(sum1 == sum2)
            return sum1;
    }
}

int main(){
    
    return 0;
}
