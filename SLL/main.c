#include <stdio.h>
#include "list.h"

int main() {
    list l;
    init_sll(&l);
    printf("Appending at the end of the list\n");
    append(&l, 12);
    append(&l, 32);
    append(&l, 69);
    traverse(l);
    printf("Inserting at begining\n");
    insert_at_beg(&l, 23);
    traverse(l);
    printf("Removing element at position 1(assuming indexing starts from 0)\n");
    remove_at_pos(&l, 1);
    traverse(l);
    printf("len = %d\n", len(l));
    return 0;
}
