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

result *str_v2(char *str1, char *str2) {
    char *p = str1, *max_seq=NULL, *start=str1;
    int max_count = 0, count = 0;

    while(*p != '\0') {
        if(*p == str2[count]) {
            count++;
        }else {
            count = 0;
            start = p+1;
        }
        if(count > max_count) {
            max_count = count;
            max_seq = start;
        }
        p++;
    }
    result  *r;
    r = (result *) malloc(sizeof(result));
    r->len = max_count;
    r->seq = max_seq;
    return r;
}

int main() {
    char str1[] = "abcdemnopxyz";
    char str2[] = "mnotq";
    result *p = str(str1, str2);
    printf("Longest subsequence: %s,\ncharacters matched: %d\n", p->seq, p->len);
    return 0;
}