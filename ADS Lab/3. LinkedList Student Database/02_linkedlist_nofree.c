#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll_no;
    char name[50];
    float cgpa;
    struct Student* next;
};

struct Student* createStudent(int roll_no, const char* name, float cgpa) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    if (!newStudent) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newStudent->roll_no = roll_no;
    strncpy(newStudent->name, name, sizeof(newStudent->name) - 1);
    newStudent->name[sizeof(newStudent->name) - 1] = '\0'; 
    newStudent->cgpa = cgpa;
    newStudent->next = NULL;
    return newStudent;
}

void displayStudents(struct Student* head) {
    struct Student* current = head;
    while (current != NULL) {
        printf("Roll No: %d, Name: %s, CGPA: %.2f\n", current->roll_no, current->name, current->cgpa);
        current = current->next;
    }
}


int main() {
    struct Student* head = NULL; 
    struct Student* temp = NULL; 
    int n, roll_no;
    char name[50];
    float cgpa;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter roll number, name, and CGPA for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &roll_no);
        printf("Name: ");
        scanf(" %[^\n]", name); 
        printf("CGPA: ");
        scanf("%f", &cgpa);

        temp = createStudent(roll_no, name, cgpa);
        temp->next = head; 
        head = temp; 
    }
    printf("\nStudent List:\n");
    displayStudents(head);
    return 0;
}
