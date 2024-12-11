#include <stdio.h>
#include "list.h"

int main() {
    list l, l2;
    init(&l);
    printf("Inserting from beginiing: \n");
    insert_from_begining(&l, 23);
    insert_from_begining(&l, 37);
    printLR(l); 

    printf("Inserting at the end: \n");
    insert_end(&l, 57);
    insert_end(&l, 5);
    insert_end(&l, 33);
    insert_end(&l, 33);
    insert_end(&l, 9);
    insert_end(&l, 69);
    insert_end(&l, 69);
    insert_end(&l, 8);
    printLR(l);

    printf("Removing duplicates: \n");
    remove_duplicates(&l);
    printLR(l);

    printf("Sorting: \n");
    sort(l);
    printLR(l);

    printf("Removing element at the end: \n");
    remove_end(&l);
    printLR(l);

    printf("Removing element from the begining: \n");
    remove_beg(&l);
    printLR(l);

    printf("Inserting at index 2 (assuming indexing starts at 0) \n");
    insert_at_index(&l, 69, 2);
    printLR(l);

    printf("Removing element at index 1 (assuming indexing starts at 0) \n");
    remove_at_index(&l, 1);
    printLR(l);

    printf("Printing Right to left: \n");
    printRL(l);

    if(is_palindrome(l))
        printf("l is palindrome\n");
    else
        printf("l is not palindrome\n");
    
    init(&l2);
    insert_end(&l2, 12);
    insert_end(&l2, 11);
    insert_end(&l2, 12);
    printf("l2 = ");
    printLR(l2);
    if(is_palindrome(l2))
        printf("l2 is palindrome\n");
    else
        printf("l2 is not palindrome\n");
    return 0;
}
