#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int *read_time(char *time_string) {
    char *token = NULL;
    int *result = (int *) malloc(sizeof(int) * 2);
    token = strtok(time_string, ":");
    result[0] = atoi(token);
    token = strtok(NULL, ":");
    result[1] = atoi(token);
    return result;
}

void print_array(int *arr, int len) {
    printf("[\t");
    for(int i = 0; i < len; i++) {
        printf("%d\t", arr[i]);
    }
    printf("]\n");
    return;
}

int to_minutes(int *time) {
    return time[0] * 60 + time[1];
}

short int compare_time(int *time1, int *time2) {
    int minutes_1, minutes_2;
    minutes_1 = to_minutes(time1); 
    minutes_2 = to_minutes(time2);
    return fabs(minutes_1 - minutes_2);
}

int main() {
    char *str1 = "23:59",*str2 = "23:58";
    int *time_1 = read_time(str1), *time_2 = read_time(str2);
    print_array(time_1, 2);
    print_array(time_2, 2);
    printf("result = %d\n", compare_time(time_1, time_2));
    return 0;
} 
