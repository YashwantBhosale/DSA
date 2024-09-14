#include <stdio.h>
#include "cll.h"

int main() {
    list l;
    init_cll(&l);
    insert_beg(&l, 12);
    insert_beg(&l, 33);
    insert_end(&l, 32);
    insert_pos(&l, 1, 7);
    insert_pos(&l, 2, 8);
    display(l);
    sort(&l);
    display(l);
    /*
    remove_beg(&l);
    display(l);
    remove_end(&l);
    display(l);
    remove_pos(&l, 1);
    display(l);
    */
    return 0;
}