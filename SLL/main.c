#include <stdio.h>
#include "list.h"

int main() {
    list l;
    init_sll(&l);
    append(&l, 12);
    append(&l, 32);
    append(&l, 69);
    traverse(l);
    insert_at_beg(&l, 23);
    remove_at_pos(&l, 1);
    traverse(l);
    printf("len = %d\n", len(l));
    return 0;
}
