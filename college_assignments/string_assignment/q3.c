//  Write a function which finds the longest possible subsequence of one string into another and returns the length + pointer to the subsequence.
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int len;
    char *seq;
} result;

result *str(char *str1, char *str2) {
    char *p = str1;
    int max = 0;
    char *max_seq = NULL;
    while(*p != '\0') {
        int count = 0;
        while(p[count] == str2[count]){
            count++;
        }
        if(count > max) {
            max = count;
            max_seq = p;
        }

        count = 0;
        p++;
    }

    result *return_result = (result *) malloc(sizeof(result));
    return_result -> len = max;
    return_result -> seq = max_seq;
    return return_result;
}

int main() {
    char str1[] = "abcdemnopxyz";
    char str2[] = "mnotq";
    result *p = str(str1, str2);
    printf("Longest subsequence: %s,\ncharacters matched: %d\n", p->seq, p->len);
    return 0;
}