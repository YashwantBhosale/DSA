#include <stdio.h>
#include <stdlib.h>

typedef struct member {
    char name[128];
    char address[128];
    char grade;
    int no_of_rooms;
    int charges;
} member;

member *members[64];

void init() {
    for(int i = 0; i < 64; i ++) {
        members[i] = NULL;
    }
}

int main() {
    init();
    return 0;
}