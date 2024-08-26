#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char firstName[64];
    char middleName[64];
    char lastName[64];
} Name;

typedef struct date{
    int day;
    int month;
    int year;
} date;

typedef struct  {
    int english_marks;
    int mathematics_marks;
    int cs_marks;
} marks;

typedef struct data {
    Name name;
    int rollno;
    char gender[64];
    date date;
    marks marks;
} student_data;

student_data *students[512];
int data_pointer = 0;

void init() {
    for(int i = 0; i < 512; i++){
        students[i] = NULL;
    }
}

void append_student(Name name, int rollno, char gender[], date date, marks marks) {
    if (data_pointer >= 512) {
        printf("Error: Cannot add more students, array is full.\n");
        return;
    }
    students[data_pointer] = (student_data *)malloc(sizeof(student_data));
    
    strcpy(students[data_pointer]->name.firstName, name.firstName);
    strcpy(students[data_pointer]->name.middleName, name.middleName);
    strcpy(students[data_pointer]->name.lastName, name.lastName);

    students[data_pointer]->rollno = rollno;

    strcpy(students[data_pointer]->gender, gender);

    students[data_pointer]->date.day = date.day;
    students[data_pointer]->date.month = date.month;
    students[data_pointer]->date.year = date.year;

    students[data_pointer]->marks.english_marks = marks.english_marks;
    students[data_pointer]->marks.mathematics_marks = marks.mathematics_marks;
    students[data_pointer]->marks.cs_marks = marks.cs_marks;

    data_pointer++;
}

void display_students() {
    int i = 0;
    while(students[i] != NULL) {
        printf("Name: %s ", students[i]->name.firstName);
        printf("%s ", students[i]->name.middleName);
        printf("%s\n", students[i]->name.lastName);
        printf("rollno: %d\n", students[i]->rollno);
        printf("Gender: %s\n", students[i]->gender);
        printf("dob: %d / %d / %d\n", students[i]->date.day, students[i]->date.month, students[i]->date.year);
        printf("Marks:\nEnglish: %d\nMathematics: %d\nComputer Science: %d\n", students[i]->marks.english_marks, students[i]->marks.mathematics_marks, students[i]->marks.cs_marks);
        printf("average: %d\n", (students[i]->marks.english_marks + students[i]->marks.mathematics_marks+students[i]->marks.cs_marks)/3);
        printf("----------------------------------------------------------------------------\n");
        i++;
    }
}

void display_low_aggreagate_students() {
    int i = 0;
    while(students[i] != NULL) {
        if(((students[i]->marks.english_marks + students[i]->marks.mathematics_marks+students[i]->marks.cs_marks))/3 < 40){    
        printf("Name: %s ", students[i]->name.firstName);
        printf("%s ", students[i]->name.middleName);
        printf("%s\n", students[i]->name.lastName);
        printf("average: %d\n", (students[i]->marks.english_marks + students[i]->marks.mathematics_marks+students[i]->marks.cs_marks)/3);
        printf("----------------------------------------------------------------------------\n");
        }
        i++;
    }
}


int main() {
    init();
    char gender[] = "Male";
    int rollno = 1;
    marks student_marks1 = {40, 35, 35};
    // marks student_marks2 = {60, 60, 60};
    marks student_marks3 = {50, 35, 55};
    marks student_marks4 = {30, 38, 50};
    // marks student_marks5 = {55, 50, 45};
    date birthdate = {1, 1, 2000};
    date birthdate2 = {1, 1, 2001};

    Name name1 = {"yashwant", "c", "bhosale"};
    append_student(name1, rollno++, gender, birthdate, student_marks1);

    // Name name2 = {"manohar", "a", "jadhav"};
    // append_student(name2, rollno++, gender, birthdate, student_marks2);

    Name name3 = {"daulat", "S", "patil"};
    append_student(name3, rollno++, gender, birthdate, student_marks3);

    Name name4 = {"Dhruv", "m", "patil"};
    append_student(name4, rollno++, gender, birthdate2, student_marks4);

    // Name name5 = {"Rishabh", "R", "sharma"};
    // append_student(name5, rollno++, gender, birthdate2, student_marks5);

    display_students();
    printf("\n\n\n");
    printf("Low aggregate students\n");
    display_low_aggreagate_students();
}