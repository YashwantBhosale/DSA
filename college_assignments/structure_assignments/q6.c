#include <stdio.h>

typedef struct {
    int day;
    int month;
    int year;
} date;

void read_date(date* d) {
    printf("Enter day : ");
    scanf("%d", &d->day);
    printf("Enter Month: ");
    scanf("%d", &d->month);
    printf("Enter year: ");
    scanf("%d", &d->year);
    return;
}

void print_date(date d) {
    printf("Entered date: ");
    printf("%d / %d / %d\n", d.day, d.month, d.year);
    return;
}   

void validate_date(date d) {
    if(d.day > 31 || d.day < 0) {
        printf("Invalid date! Day should be less than 31.\n");
        return;
    }
    if(d.month > 12 || d.month < 0){
        printf("Invalid Month!\n");
        return;
    }
    if(d.year < 0) {
        printf("Invalid year!\n");
        return;
    }
    if(d.day == 29 && d.month == 2) {
        if(d.year%4 != 0) {
            printf("Invalid date! Year is not a leap year\n");
            return;
        }
        if(d.year%100 == 0 && d.year%400 != 0) {
            printf("Invalid date! Year is not a leap year\n");
            return;
        }
    }
    if(d.day >= 30 && d.month == 2){
	printf("February cannot have more than 29 days!\n");
	return;
    }
    if((d.day == 31) && (d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11)){
        printf("Invalid date! No more than 30 days for this month.\n");
        return;
    }
    printf("Valid date!\n");
    return;
}

int main () {
    date new_date;
    read_date(&new_date);
    print_date(new_date);
    validate_date(new_date);
    return 0;
}
