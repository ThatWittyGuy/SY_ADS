#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student
struct Student {
    int roll_no;
    char name[50];
    float cgpa;
    struct Student* next; // Pointer to the next student
};

// Function to create a new student node
struct Student* createStudent(int roll_no, const char* name, float cgpa) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    if (!newStudent) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newStudent->roll_no = roll_no;
    strncpy(newStudent->name, name, sizeof(newStudent->name) - 1);
    newStudent->name[sizeof(newStudent->name) - 1] = '\0'; // Ensure null-termination
    newStudent->cgpa = cgpa;
    newStudent->next = NULL;
    return newStudent;
}

// Function to display the student data
void displayStudents(struct Student* head) {
    struct Student* current = head;
    while (current != NULL) {
        printf("Roll No: %d, Name: %s, CGPA: %.2f\n", current->roll_no, current->name, current->cgpa);
        current = current->next;
    }
}

// Main function
int main() {
    struct Student* head = NULL; // Initialize the head of the list
    struct Student* temp = NULL; // Temporary pointer for new students
    int n, roll_no;
    char name[50];
    float cgpa;

    // Input the number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Loop to input student details
    for (int i = 0; i < n; i++) {
        printf("Enter roll number, name, and CGPA for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &roll_no);
        printf("Name: ");
        scanf(" %[^\n]", name); // Read string with spaces
        printf("CGPA: ");
        scanf("%f", &cgpa);

        // Create a new student and add it to the list
        temp = createStudent(roll_no, name, cgpa);
        temp->next = head; // Point new student to the current head
        head = temp; // Update head to new student
    }

    // Displaying the students
    printf("\nStudent List:\n");
    displayStudents(head);

    // Freeing the allocated memory
    struct Student* current = head;
    struct Student* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
