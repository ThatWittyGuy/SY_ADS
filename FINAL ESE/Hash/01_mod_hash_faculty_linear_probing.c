#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct {
    int id;
    char name[30];
} Faculty;

Faculty hashTable[TABLE_SIZE];

int hashFunction(int id) {
    return id % TABLE_SIZE;
}

void insert(int id, char name[]) {
    int index = hashFunction(id);
    int i = index;
    while (hashTable[i].id != 0) {
        i = (i + 1) % TABLE_SIZE;
        if (i == index) {
            printf("Hash table is full\n");
            return;
        }
    }
    hashTable[i].id = id;
    strcpy(hashTable[i].name, name);
}

Faculty* search(int id) {
    int index = hashFunction(id);
    int i = index;
    while (hashTable[i].id != 0) {
        if (hashTable[i].id == id) {
            return &hashTable[i];
        }
        i = (i + 1) % TABLE_SIZE;
        if (i == index) {
            break;
        }
    }
    return NULL;
}

void display() {
    printf("\nFaculty Database:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].id != 0) {
            printf("ID: %d, Name: %s\n", hashTable[i].id, hashTable[i].name);
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
                getchar(); // To consume the newline character left by scanf
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character
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
