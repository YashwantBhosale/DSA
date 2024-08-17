#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int hours;
    int minutes;
    int seconds;
} time;

void read_time(time *t) {
    printf("Enter hours: ");
    scanf("%d", &t->hours);
    printf("Enter minutes: ");
    scanf("%d", &t->minutes);
    printf("Enter seconds: ");
    scanf("%d", &t->seconds);
    return;
}

void print_time(time t) {
    printf("Time: %d : %d : %d\n", t.hours, t.minutes, t.seconds);
    return;
}

time *add_time(time t1, time t2) {
    time  *t3 = (time *) malloc(sizeof(time));
    t3->seconds = t1.seconds + t2.seconds;
    t3->minutes = t1.minutes + t2.minutes;
    t3->hours = t1.hours + t2.hours;
    if(t3->seconds >= 60){
        t3->seconds = t3->seconds - 60;
        t3->minutes++;
    }
    if(t3->minutes >= 60){
        t3->minutes -= 60;
        t3->hours++;
    }
    return t3;
}

int compare_time(time t1, time t2) {
    if(t1.hours > t2.hours) 
        return 1;
    else if(t1.hours < t2.hours)
        return -1;
    else if(t1.minutes > t2.minutes)
        return 1;
    else if(t1.minutes < t2.minutes)
        return -1;
    else if(t1.seconds > t2.seconds)
        return 1;
    else if(t1.seconds < t2.seconds)
        return -1;
    else
        return 0;
}

time *subtract_time(time t1, time t2) {
    time *t3 = (time *) malloc(sizeof(time));
    time larger_t, smaller_t;
    int result = compare_time(t1, t2);
    if(!result) {
        t3->hours = 0;
        t3->minutes = 0;
        t3->seconds = 0;
        return t3;
    }else if(result == 1) {
        larger_t = t1;
        smaller_t = t2;
    }else {
        larger_t = t1;
        smaller_t = t2;
    }
    t3->hours = larger_t.hours - smaller_t.hours;
    if(larger_t.minutes < smaller_t.minutes){
        t3->minutes = 60 - (smaller_t.minutes - larger_t.minutes);
        t3->hours--;
    }else{
        t3->minutes = larger_t.minutes - smaller_t.minutes;
    }
    if(larger_t.seconds < smaller_t.seconds){
        t3->seconds = 60 - (smaller_t.seconds - larger_t.seconds);
        t3->minutes--;
    }else{
        t3->seconds = larger_t.seconds - smaller_t.seconds;
    }
    return t3;
}

int main() {
    int option;
    time t1, t2, *t3;
    t3 = (time *) malloc(sizeof(time));
    read_time(&t1);
    read_time(&t2);
    printf("1. Add dates\n2. Subtract dates\n");
    printf("Enter option: ");
    scanf("%d", &option);
    switch (option) {
        case 1: {
            t3 = add_time(t1, t2);
	    break;
	}
        case 2: {
            t3 = subtract_time(t1, t2);
	    break;
        }
        default: {
            t3 -> hours = 0;
            t3 -> minutes = 0;
            t3 -> seconds = 0;
	    break;
        }
    }
    printf("Result ");
    print_time(*t3);
    return 0;
}
