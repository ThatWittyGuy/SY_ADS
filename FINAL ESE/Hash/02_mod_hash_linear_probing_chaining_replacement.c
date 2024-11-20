#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Faculty {
    int id;
    char name[30];
    struct Faculty* next;
} Faculty;

Faculty* hashTable[TABLE_SIZE];

int hashFunction(int id) {
    return id % TABLE_SIZE;
}

void insert(int id, char name[]) {
    int index = hashFunction(id);
    Faculty* newFaculty = (Faculty*)malloc(sizeof(Faculty));
    newFaculty->id = id;
    strcpy(newFaculty->name, name);
    newFaculty->next = NULL;
    
    if (hashTable[index] == NULL) {
        hashTable[index] = newFaculty;
    } else {
        Faculty* temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newFaculty;
    }
}

Faculty* search(int id) {
    int index = hashFunction(id);
    Faculty* temp = hashTable[index];
    while (temp != NULL) {
        if (temp->id == id) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void display() {
    printf("\nFaculty Database:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        Faculty* temp = hashTable[i];
        while (temp != NULL) {
            printf("ID: %d, Name: %s\n", temp->id, temp->name);
            temp = temp->next;
        }
    }
}

int main() {
    int choice, id;
    char name[30];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Faculty\n");
        printf("2. Search Faculty\n");
        printf("3. Display All Faculty\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Faculty ID: ");
                scanf("%d", &id);
                printf("Enter Faculty Name: ");
                getchar();
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                insert(id, name);
                break;

            case 2:
                printf("Enter Faculty ID to search: ");
                scanf("%d", &id);
                Faculty* faculty = search(id);
                if (faculty != NULL) {
                    printf("Found Faculty: ID: %d, Name: %s\n", faculty->id, faculty->name);
                } else {
                    printf("Faculty with ID %d not found.\n", id);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}



// Key Features:

//     Hash Function: The hashFunction uses the modulus operation to determine the index.
//     Chaining with Replacement: Each hash table slot holds a linked list. When a collision occurs (multiple records have the same hash value), the new faculty is added to the end of the linked list.
//     Menu-Driven Program: The user can insert faculty records, search for a faculty member by ID, display all faculty records, or exit the program.

// Sample Input and Output:
// Sample Run:

// Menu:
// 1. Insert Faculty
// 2. Search Faculty
// 3. Display All Faculty
// 4. Exit
// Enter your choice: 1
// Enter Faculty ID: 101
// Enter Faculty Name: Dr. Smith

// Menu:
// 1. Insert Faculty
// 2. Search Faculty
// 3. Display All Faculty
// 4. Exit
// Enter your choice: 1
// Enter Faculty ID: 102
// Enter Faculty Name: Dr. Johnson

// Menu:
// 1. Insert Faculty
// 2. Search Faculty
// 3. Display All Faculty
// 4. Exit
// Enter your choice: 3

// Faculty Database:
// ID: 101, Name: Dr. Smith
// ID: 102, Name: Dr. Johnson

// Menu:
// 1. Insert Faculty
// 2. Search Faculty
// 3. Display All Faculty
// 4. Exit
// Enter your choice: 2
// Enter Faculty ID to search: 101
// Found Faculty: ID: 101, Name: Dr. Smith

// Menu:
// 1. Insert Faculty
// 2. Search Faculty
// 3. Display All Faculty
// 4. Exit
// Enter your choice: 4
// Exiting...

