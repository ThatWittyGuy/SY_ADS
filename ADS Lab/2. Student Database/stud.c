#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[50];
    float cgpa;
} stud[100];

int numStudents = 0;  

void create() {
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    if (numStudents > 100) {
        printf("Number exceeds maximum limit of 100 students\n");
        numStudents = 100;
    }
    printf("Student database created for %d students.\n", numStudents);
}

void add() {
    for (int i = 0; i < numStudents; i++) {
        if (stud[i].rollno == 0) {
            printf("Enter roll number: ");
            scanf("%d", &stud[i].rollno);
            printf("Enter name: ");
            scanf(" %[^\n]s", stud[i].name);
            printf("Enter CGPA: ");
            scanf("%f", &stud[i].cgpa);
            printf("Student added successfully at position %d.\n", i);
            return; 
        }
    }
}

void delete_student() {
    int rollno;
    printf("Enter roll number to delete: ");
    scanf("%d", &rollno);

    for (int i = 0; i < numStudents; i++) {
        if (stud[i].rollno == rollno) {
            for (int j = i; j < numStudents - 1; j++) {
                stud[j] = stud[j + 1];
            }
            stud[numStudents - 1].rollno = 0;
            strcpy(stud[numStudents - 1].name, "");
            stud[numStudents - 1].cgpa = 0.0;
            
            printf("Student with roll number %d deleted successfully.\n", rollno);
            return; 
        }
    }
}

void display() {
    printf("Student Database:\n");
    for (int i = 0; i < numStudents; i++) {
        if (stud[i].rollno != 0) { 
            printf("%d\t%s\t%.2f\n", stud[i].rollno, stud[i].name, stud[i].cgpa);
        }
    }
}

int main() {
    int choice;
    int flag = 1;

    do {
        printf("\nStudent Database Menu:\n");
        printf("1. Create\n");
        printf("2. Add Student\n");
        printf("3. Delete Student\n");
        printf("4. Display Students\n");
        printf("5. Exit\n");

        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice); 

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                add();
                break;
            case 3:
                delete_student();
                break;
            case 4:
                display();
                break;
            case 5:
                flag = 0; 
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (flag); 

    return 0;
}
