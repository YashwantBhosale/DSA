#include <stdio.h>
#include "list.h"

int main() {
    list l;
    init(&l);
    insert_end(&l, 57);
    insert_end(&l, 5);
    insert_end(&l, 33);
    insert_end(&l, 33);
    insert_end(&l, 9);
    insert_end(&l, 69);
    insert_end(&l, 69);
    insert_end(&l, 8);
    printLR(l);
    remove_duplicates(&l);
    printLR(l);
    sort(l);
    printLR(l);
    remove_end(&l);
    printLR(l);
    remove_beg(&l);
    printLR(l);
    insert_at_index(&l, 69, 2);
    printLR(l);
    remove_at_index(&l, 1);
    printLR(l);
    return 0;
}