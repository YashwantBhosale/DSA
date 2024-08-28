#include "ascii.h"

int main() {
    list l;
    init_ascii(&l);
    ascii_of(&l, 'A');
    traverse(l);
    destroy(&l);
    traverse(l);
    return 0;
}