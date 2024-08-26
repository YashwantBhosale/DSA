#include "list.h"

int main() {
    list l;
    init(&l);
    insert_end(&l, 5);
    insert_end(&l, 8);
    insert_end(&l, 9);
    printLR(l);
    remove_end(&l);
    printLR(l);
    remove_beg(&l);
    printLR(l);
    // printRL(l);
    return 0;
}