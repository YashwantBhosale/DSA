#include <stdio.h>
#include <stdlib.h>
#define ENTRIES 128
typedef struct {
    char item[64];
    int qty;
    int price;
    int amount;
} entry;
entry *bill[ENTRIES];
int bill_ptr = 0;
void init() {
    for (int i = 0; i < ENTRIES; i++) {
        bill[i] = NULL;
    }
    return;
}
entry *read_entry() {
    entry *e = (entry *)malloc(sizeof(entry));
    printf("Item Quantity price\n");
    scanf("%s%d%d", e->item, &e->qty, &e->price);
    return e;
}
void add_entry(entry *e) {
    bill[bill_ptr] = e;
    bill_ptr++;
    return;
}
void print_bill() {
    int total_amount = 0;
    printf(
        "********************************BILL**********************************"
        "*********\n\n");
    printf("Item\t\tQuantity\tPrice\t\tAmount\n");
    for (int i = 0; i < bill_ptr; i++) {
        printf("%s\t\t", bill[i]->item);
        printf("%d\t\t", bill[i]->qty);
        printf("%d\t\t", bill[i]->price);
        printf("%d\t\t", bill[i]->price * bill[i]->qty);
        printf(
            "\n----------------------------------------------------------------"
            "----------------------\n");
        total_amount += bill[i]->price * bill[i]->qty;
    }
    printf("Total amount to be paid = %d\n", total_amount);
    return;
}

void print_menu() {
    printf("\n------------------------------------------------------------------------------------------\n");
    printf("1. Add Entry\n2. View Bill\n3.Exit\n");
    printf("Enter option: ");
}

void read_option(int option) {
    switch (option) {
        case 1: {
            add_entry(read_entry());
            printf("Entry added successfully!\n");
            break;
        }
        case 2: {
            print_bill();
            break;
        }
        case 3: {
            return;
        }
        default: {
            printf("Invalid option\n");
            break;
        }
    }
    return;
}

int main() {
    int option;
    while(1){
        print_menu();
        scanf("%d", &option);
        read_option(option);
        if(option == 3) {
            break;
        }
    }

    return 0;
}