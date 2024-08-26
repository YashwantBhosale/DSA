#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[128];
    char address[128];
    char grade;
    int no_of_rooms;
    int charges;
} hotel;

hotel *hotels[64];
int hotel_pointer = 0;


void init() {
    for(int i = 0; i < 64; i ++) {
        hotels[i] = NULL;
    }
    return;
}

void append_member(char name[], char address[], char grade, int no_of_rooms, int charges) {
    if (hotel_pointer >= 64) {
        return;
    }
    hotels[hotel_pointer] = (hotel *)malloc(sizeof(hotel));
    strcpy(hotels[hotel_pointer]->name, name);
    strcpy(hotels[hotel_pointer]->address, address);
    hotels[hotel_pointer]->grade = grade;
    hotels[hotel_pointer]->no_of_rooms = no_of_rooms;
    hotels[hotel_pointer]->charges = charges;
    hotel_pointer++;
    return;
}

void filter_by_grade(char grade) {
    for(int i = 0; i < 64; i++) {
        if (hotels[i] != NULL && hotels[i]->grade == grade) {
            printf("%s\n", hotels[i]->name);
        }
    }
    return;
}

void filter_by_charges(int charges) {
    for(int i = 0; i < 64; i++) {
        if (hotels[i] != NULL && hotels[i]->charges < charges) {
            printf("%s\n", hotels[i]->name);
        }
    }
    return;
}


int main() {
    init();
    append_member("Hotel 1", "Address 1", 'A', 100, 1000);
    append_member("Hotel 2", "Address 2", 'B', 200, 2000);
    append_member("Hotel 3", "Address 3", 'A', 300, 3000);
    append_member("Hotel 4", "Address 4", 'B', 400, 4000);
    append_member("Hotel 5", "Address 5", 'A', 500, 5000);
    append_member("Hotel 6", "Address 6", 'B', 600, 6000);
    printf("Hotels with grade A:\n");
    filter_by_grade('A');
    printf("\n");
    printf("Hotels with charges less than 3000:\n");
    filter_by_charges(3000);
    return 0;
}