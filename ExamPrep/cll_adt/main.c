#include <stdio.h>
#include "cll.h"

int main() {
    list l;
    init_cll(&l);
    printf("Inserting from beginiing: \n");
    insert_beg(&l, 12);
    insert_beg(&l, 33);
    display(l);
    
    printf("Inserting at the end: \n");
    insert_end(&l, 32);
    insert_end(&l, 37);
    display(l);

    printf("Inserting at index 1 (and 2) (assuming index starts from 0)\n");
    insert_pos(&l, 1, 7);
    insert_pos(&l, 2, 8);
    display(l);

    printf("Sorting: \n");
    sort(&l);
    display(l);

    printf("Removing element from the begining: \n");
    remove_beg(&l);
    display(l);

    printf("Removing element at the end: \n");    
    remove_end(&l);
    display(l);

    printf("Removing element at index 1 (assuming indexing starts at 0) \n");    
    remove_pos(&l, 1);
    display(l);
    return 0;
}
