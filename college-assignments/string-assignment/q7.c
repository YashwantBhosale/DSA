#include <stdio.h>
#include <string.h>

char toLowerCase(char c) {
    if(c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }else{
        return c;
    }
}

int str_case_cmp(char *s1, char *s2) {
    int i = 0;
    while(s1[i] != '\0' || s2[i] != '\0') {
        if(toLowerCase(s1[i]) == toLowerCase(s2[i])) {
            i++;
            continue;
        }else {
            return (toLowerCase(s1[i]) - toLowerCase(s2[i]));
        }
    }
    return 0;
}

int str_coll(char *s1, char *s2) {
    int i = 0;
    while(s1[i] != '\0' || s2[i] != '\0') {
        if(s1[i] == s2[i]) {
            i++;
            continue;
        }else {
            return s1[i] - s2[i];
        }
    }
    return 0;
}

int main() {
    char str1[64], str2[64], ch;
    printf("Enter strings: ");
    scanf("%s%s", str1, str2);
    printf("strcasecmp: %d\nstr_case_cmp: %d\nstrcoll: %d\nstr_coll: %d\nstrcmp: %d\n", strcasecmp(str1, str2), str_case_cmp(str1, str2), strcoll(str1, str2), str_coll(str1, str2), strcmp(str1, str2));
    return 0;
}
