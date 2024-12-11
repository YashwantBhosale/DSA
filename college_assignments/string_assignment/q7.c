#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char toLowerCase(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    } else {
        return c;
    }
}

int str_case_cmp(char *s1, char *s2) {
    int i = 0;
    while (s1[i] != '\0' || s2[i] != '\0') {
        if (toLowerCase(s1[i]) == toLowerCase(s2[i])) {
            i++;
            continue;
        } else {
            return (toLowerCase(s1[i]) - toLowerCase(s2[i]));
        }
    }
    return 0;
}

int str_coll(char *s1, char *s2) {
    int i = 0;
    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] == s2[i]) {
            i++;
            continue;
        } else {
            return s1[i] - s2[i];
        }
    }
    return 0;
}

char *str_sep(char **str, const char *delim) {
    char *p = *str;
    char *start = *str;
    if (p == NULL) {
        return NULL;
    }
    // Find first occurrence of delim in str
    while (*p != '\0' && *p != *delim) {
        p++;
    }

    if (*p == '\0') {
        *str = NULL;
        return start;
    } else {
        *p = '\0';    
        *str = p + 1; 
        return start;
    }
}

void view_menu() {
    printf("1.str_case_cmp\n2.str_coll\n3.str_sep\n4.Exit\n");
    return;
}

void read_command(int option) {
    switch (option)
    {
    case 1:
        printf("Enter two strings: ");
        char str1[64], str2[64];
        scanf("%s%s", str1, str2);
        printf("str_case_cmp: %d\n", str_case_cmp(str1, str2));
        if(str_case_cmp(str1, str2) > 0) {
            printf("String 1 is greater than String 2\n");
        } else if(str_case_cmp(str1, str2) < 0) {
            printf("String 1 is less than String 2\n");
        } else {
            printf("Strings are equal\n");
        }
        break;
    case 2:
        printf("Enter two strings: ");
        char str3[64], str4[64];
        scanf("%s%s", str3, str4);
        printf("str_coll: %d\n", str_coll(str3, str4));
        if(str_coll(str3, str4) > 0) {
            printf("String 1 is greater than String 2\n");
        } else if(str_coll(str3, str4) < 0) {
            printf("String 1 is less than String 2\n");
        } else {
            printf("Strings are equal\n");
        }
        break;
    case 3:
        printf("Enter string and delimiter: ");
        char str5[64], delim[64];
        scanf("%s%s", str5, delim);
        char *token;
        char *rest = str5;
        while ((token = str_sep(&rest, delim)) != NULL) {
            printf("%s\n", token);
        }
        break;
    case 4:
        exit(0);
    default:
        break;
    }
}

int main() {
    view_menu();
    int option;
    while(1) {
        printf("Enter option: ");
        scanf("%d", &option);
        read_command(option);
    }
    return 0;
}
