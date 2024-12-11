#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void display_menu() {
    printf("Choose operation using number:\n");
    printf("1. Display Stack\n");
    printf("2. Push element into the stack\n");
    printf("3. Pop element from the stack\n");
    printf("4. View top element of the stack\n");
    printf("5. Exit\n");
    return;
}

void read_option(int option, stack *s) {
    switch (option){
    case 1:{
        display(*s);
        break;
    }
    case 2: {
        int data;
        printf("Enter Data: ");
        scanf("%d", &data);
        push(s, data);
        break;
    }
    case 3: {
        pop(s);
        break;
    }
    case 4: {
        printf("top = %d\n", peek(*s));
        break;
    }
    default:
        printf("Invalid Option\n");
        break;
    }
    return;
}

int main() {
    int option = 0;        
    stack s;
    init(&s, 3);
    /*
    push(&s, 10);
    push(&s,12);
    display(s);
    printf("Peeking stack: %d\n", peek(s));
    printf("Popping element: %d\n", pop(&s));
    display(s);
    */
    while(1) {
        display_menu();
        printf("Enter option: ");
        scanf("%d", &option);
        if(option == 5)
            break;
        read_option(option, &s);
        printf("\n");
    }

    return 0;
}
