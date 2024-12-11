#include <stdio.h>

int parse_int(char *num_string){
    int n = 0, ptr = 0, sign=1;
    if(num_string[0] == '-') {
        sign = -1;
        ptr++;
    }
    while(num_string[ptr] >= '0' && num_string[ptr] <= '9' && num_string[ptr] != '\0'){
        n = n * 10 + (num_string[ptr] - '0');
        ptr++;
    }
    return n * sign;
}

int main() {
    char num_str[64];
    printf("Enter a number string: ");
    scanf("%s", num_str);
    printf("%d\n", parse_int(num_str));
    return 0;
}
