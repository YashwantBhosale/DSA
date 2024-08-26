#include <stdio.h>
#include <stdlib.h>

typedef struct time {
	unsigned int hours;
	unsigned int minutes;
	unsigned int seconds;
}time;

void print(time start_time, time end_time) {
	printf("\n");
	while((start_time.hours != end_time.hours) || (start_time.minutes != end_time.minutes) || (start_time.seconds != end_time.seconds)) {
		start_time.seconds++;
		if(start_time.seconds == 60)
			start_time.minutes++;
		if(start_time.minutes == 60)
			start_time.hours++;
		printf("GOOD DAY!\n");
	}
}

int main() {
	time start_time, end_time;
	
	printf("Enter start time: \n");
	printf("hours: ");
	scanf("%d", &start_time.hours);
	printf("\nminutes: ");
	scanf("%d", &start_time.minutes);
	printf("\nseconds: ");
	scanf("%d", &start_time.seconds);

	printf("\n");

	printf("Enter end time: \n");
	printf("hours: ");
	scanf("%d", &end_time.hours);
	printf("\nminutes: ");
	scanf("%d", &end_time.minutes);
	printf("\nseconds: ");
	scanf("%d", &end_time.seconds);

	print(start_time, end_time);
	return 0;
}
