#include <stdio.h>
#include "ascii.h"

int main() {
    list l;
    char c;

    printf("Enter a character: ");
    scanf("%c", &c);
    init_ascii(&l);
    ascii_of(&l, c);
    traverse(l);
    destroy(&l);
    traverse(l);
    return 0;
}
