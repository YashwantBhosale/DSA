#include <stdio.h>
#include "queue.h"

void view_menu(){
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Print\n");
    printf("4. Exit\n");
    return;
}

void evaluate_option(queue *q, int option){
    int data;
    switch(option){
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            enq(q, data);
            break;
        case 2:
            deq(q);
            break;
        case 3:
            print(q);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid option\n");
    }

    printf("-------------------------------------------------------------------\n");
    return;
}

int main() {
    queue q;
    init(&q);
    int option;
    while(1){
        view_menu();
        printf("Enter option: ");
        scanf("%d", &option);
        if(option == 4) break;
        evaluate_option(&q, option);
    }
    destroy(&q);
    return 0;
}
