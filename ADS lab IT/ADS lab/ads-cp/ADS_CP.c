#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEM_NAME_LEN 100
#define MAX_NAME_LEN 50
#define MAX_CONTACT_LEN 11
#define MAX_USERS 100

#define USER_FILE "users.txt"
#define DOCTOR_FILE "doctor.txt"
#define NURSE_FILE "nurses.txt"
#define PATIENT_FILE "patients.txt"
#define INVENTORY_FILE "inventory.txt"
#define APPOINTMENT_FILE "appointments.txt"



typedef struct Pediatricians {
    int id;
    char name[MAX_NAME_LEN];
    int age;
    char contactNumber[MAX_CONTACT_LEN];
    int experience;
    struct Pediatricians *next;
} Pediatricians;
Pediatricians* head1 = NULL;

typedef struct Neurosurgeons {
    int id;
    char name[MAX_NAME_LEN];
    int age;
    char contactNumber[MAX_CONTACT_LEN];
    int experience;
    struct Neurosurgeons *next;
} Neurosurgeons;
Neurosurgeons *head2=NULL;

typedef struct Cardiologists {
    int id;
    char name[MAX_NAME_LEN];
    int age;
    char contactNumber[MAX_CONTACT_LEN];
    int experience;
    struct Cardiologists *next;
} Cardiologists;
Cardiologists *head3=NULL;


typedef struct Optiologists {
    int id;
    char name[MAX_NAME_LEN];
    int age;
    char contactNumber[MAX_CONTACT_LEN];
    int experience;
    struct Optiologists *next;
} Optiologists;
Optiologists *head4 = NULL;

typedef struct GeneralPhysicians {
    int id;
    char name[MAX_NAME_LEN];
    int age;
    char contactNumber[MAX_CONTACT_LEN];
    int experience;
    struct GeneralPhysicians *next;
} GeneralPhysicians;
GeneralPhysicians *head5 = NULL;

typedef struct Nurse {
    int id;
    char name[MAX_NAME_LEN];
    char doctorAssigned[MAX_NAME_LEN];
    struct Nurse *next;
} *Nurse;
Nurse headNurse = NULL;

typedef struct Patient {
    int id;
    char name[MAX_NAME_LEN];
    float totalBill;
    struct Patient* next;
} Patient;

Patient* patientHead = NULL;

typedef struct InventoryItem {
    int id;
    char itemName[MAX_ITEM_NAME_LEN];
    int quantity;
    struct InventoryItem* next;
} InventoryItem;

InventoryItem* inventoryHead = NULL;

int doctorCount = 0, nurseCount = 0, patientCount = 0, inventoryCount = 0, appointmentCount = 0;


void doc_to_file(int choice, int id, const char *name, int age, const char *contactNumber, int experience) {
    FILE *file;


    file = fopen(DOCTOR_FILE, "a+");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }


    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);


    if (fileSize == 0) {
        fprintf(file, "%-8s %-20s %-5s %-15s %-20s %-20s\n", "ID No.", "Name", "Age", "Contact No.", "Years of Experience", "Specialty");
    }


    const char *specialty;
    switch (choice) {
        case 1: specialty = "Pediatricians"; break;
        case 2: specialty = "Neurosurgeons"; break;
        case 3: specialty = "Cardiologists"; break;
        case 4: specialty = "Optiologists"; break;
        case 5: specialty = "General Physicians"; break;
        default: specialty = "Unknown"; break;
    }


    fprintf(file, "%-8d %-20s %-5d %-15s %-20d %-20s\n", id, name, age, contactNumber, experience, specialty);

    fclose(file);
}




void Add_Doctor() {
    int choice;
    printf("\n=====================================================\n");
    printf("                  Add Doctor\n");
    printf("=====================================================\n");
    printf("1. Pediatricians\n");
    printf("2. Neurosurgeons\n");
    printf("3. Cardiologists\n");
    printf("4. Optiologists\n");
    printf("5. General Physicians\n");
    printf("=====================================================\n");
    printf("Select the department (1-5): ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 5) {
        printf("Invalid choice!\n");
        return;
    }

    int id;
    char name[MAX_NAME_LEN];
    int age, experience;
    char contactNumber[MAX_CONTACT_LEN];

    printf("Enter doctor's ID: ");
    scanf("%d", &id);
    printf("Enter doctor's name: ");
    scanf(" %[^\n]s", name);
    printf("Enter doctor's age: ");
    scanf("%d", &age);
    printf("Enter doctor's contact number: ");
    scanf("%s", contactNumber);
    printf("Enter doctor's experience (years): ");
    scanf("%d", &experience);


     doc_to_file(choice, id, name, age, contactNumber, experience);


    switch (choice) {
        case 1: {
            Pediatricians *new_node = (Pediatricians*)malloc(sizeof(Pediatricians));
            new_node->id = id;
            strcpy(new_node->name, name);
            new_node->age = age;
            strcpy(new_node->contactNumber, contactNumber);
            new_node->experience = experience;
            new_node->next = head1;
            head1 = new_node;
            break;
        }
        case 2: {
            Neurosurgeons *new_node = (Neurosurgeons*)malloc(sizeof(Neurosurgeons));
            new_node->id = id;
            strcpy(new_node->name, name);
            new_node->age = age;
            strcpy(new_node->contactNumber, contactNumber);
            new_node->experience = experience;
            new_node->next = head2;
            head2 = new_node;
            break;
        }
        case 3: {
            Cardiologists *new_node = (Cardiologists*)malloc(sizeof(Cardiologists));
            new_node->id = id;
            strcpy(new_node->name, name);
            new_node->age = age;
            strcpy(new_node->contactNumber, contactNumber);
            new_node->experience = experience;
            new_node->next = head3;
            head3 = new_node;
            break;
        }
        case 4: {
            Optiologists *new_node = (Optiologists*)malloc(sizeof(Optiologists));
            new_node->id = id;
            strcpy(new_node->name, name);
            new_node->age = age;
            strcpy(new_node->contactNumber, contactNumber);
            new_node->experience = experience;
            new_node->next = head4;
            head4 = new_node;
            break;
        }
        case 5: {
            GeneralPhysicians *new_node = (GeneralPhysicians*)malloc(sizeof(GeneralPhysicians));
            new_node->id = id;
            strcpy(new_node->name, name);
            new_node->age = age;
            strcpy(new_node->contactNumber, contactNumber);
            new_node->experience = experience;
            new_node->next = head5;
            head5 = new_node;
            break;
        }
    }

    doctorCount++;
    printf("Doctor added successfully!\n");
}



int del_doctor() {
    int choice;
    char nameToDelete[MAX_NAME_LEN];

    printf("\n=====================================================\n");
    printf("                  Delete Doctor\n");
    printf("=====================================================\n");
    printf("Select the department to delete a doctor from:\n");
    printf("1. Pediatricians\n");
    printf("2. Neurosurgeons\n");
    printf("3. Cardiologists\n");
    printf("4. Optiologists\n");
    printf("5. General Physicians\n");
    printf("=====================================================\n");
    printf("Select the department (1-5): ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 5) {
        printf("Invalid choice!\n");
        return -1;
    }

    printf("Enter the name of the doctor to delete: ");
    scanf(" %[^\n]s", nameToDelete);


    FILE *file = fopen(DOCTOR_FILE, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    if (file == NULL || tempFile == NULL) {
        printf("Error opening file!\n");
        return -1;
    }

    char line[256];
    int found = 0;
    int isFirstLine = -1;

    while (fgets(line, sizeof(line), file)) {

            if (isFirstLine) {
            fprintf(tempFile, "%s", line);
            isFirstLine = 0;
            continue;
        }

        int id, age, experience;
        char name[MAX_NAME_LEN], contactNumber[MAX_CONTACT_LEN], specialty[20];


        sscanf(line, "%d %[^ ] %d %[^ ] %d %s", &id, name, &age, contactNumber, &experience, specialty);


        if (strcmp(name, nameToDelete) == 0) {
            found = 1;
            printf("Doctor %s deleted successfully.\n", name);
            continue;
        }

        fprintf(tempFile, "%-8d %-20s %-5d %-15s %-20d %-20s\n", id, name, age, contactNumber, experience, specialty);
    }

    fclose(file);
    fclose(tempFile);

    if (remove(DOCTOR_FILE) != 0 || rename("temp.txt", DOCTOR_FILE) != 0) {
        printf("Error updating doctor file!\n");
        return -1;
    }

    if (!found) {
        printf("Doctor with name %s not found.\n", nameToDelete);
        return -1;
    }


    switch (choice) {
        case 1:
            remove_from_list(&head1, nameToDelete);
            break;
        case 2:
            remove_from_list(&head2, nameToDelete);
            break;
        case 3:
            remove_from_list(&head3, nameToDelete);
            break;
        case 4:
            remove_from_list(&head4, nameToDelete);
            break;
        case 5:
            remove_from_list(&head5, nameToDelete);
            break;
    }

    doctorCount--;
    return 0;
}



void remove_from_list(void **head, const char *name, int type) {
    if (*head == NULL) return;


    switch (type) {
        case 1: {
            Pediatricians **pediatricsHead = (Pediatricians**)head;
            Pediatricians *current = *pediatricsHead;
            Pediatricians *previous = NULL;

            while (current != NULL) {
                if (strcmp(current->name, name) == 0) {
                    if (previous == NULL) {
                        *pediatricsHead = current->next;
                    } else {
                        previous->next = current->next;
                    }
                    free(current);
                    printf("Doctor %s removed from Pediatricians.\n", name);
                    return;
                }
                previous = current;
                current = current->next;
            }
            break;
        }
        case 2: {
            Neurosurgeons **neuroHead = (Neurosurgeons**)head;
            Neurosurgeons *current = *neuroHead;
            Neurosurgeons *previous = NULL;

            while (current != NULL) {
                if (strcmp(current->name, name) == 0) {
                    if (previous == NULL) {
                        *neuroHead = current->next;
                    } else {
                        previous->next = current->next;
                    }
                    free(current);
                    printf("Doctor %s removed from Neurosurgeons.\n", name);
                    return;
                }
                previous = current;
                current = current->next;
            }
            break;
        }
        case 3: {
            Cardiologists **cardioHead = (Cardiologists**)head;
            Cardiologists *current = *cardioHead;
            Cardiologists *previous = NULL;

            while (current != NULL) {
                if (strcmp(current->name, name) == 0) {
                    if (previous == NULL) {
                        *cardioHead = current->next;
                    } else {
                        previous->next = current->next;
                    }
                    free(current);
                    printf("Doctor %s removed from Cardiologists.\n", name);
                    return;
                }
                previous = current;
                current = current->next;
            }
            break;
        }
        case 4: {
            Optiologists **optoHead = (Optiologists**)head;
            Optiologists *current = *optoHead;
            Optiologists *previous = NULL;

            while (current != NULL) {
                if (strcmp(current->name, name) == 0) {
                    if (previous == NULL) {
                        *optoHead = current->next;
                    } else {
                        previous->next = current->next;
                    }
                    free(current);
                    printf("Doctor %s removed from Optiologists.\n", name);
                    return;
                }
                previous = current;
                current = current->next;
            }
            break;
        }
        case 5: {
            GeneralPhysicians **genPhysHead = (GeneralPhysicians**)head;
            GeneralPhysicians *current = *genPhysHead;
            GeneralPhysicians *previous = NULL;

            while (current != NULL) {
                if (strcmp(current->name, name) == 0) {
                    if (previous == NULL) {
                        *genPhysHead = current->next;
                    } else {
                        previous->next = current->next;
                    }
                    free(current);
                    printf("Doctor %s removed from General Physicians.\n", name);
                    return;
                }
                previous = current;
                current = current->next;
            }
            break;
        }
        default:
            printf("Invalid type specified for removal.\n");
            break;
    }

    printf("Doctor %s not found in the specified department.\n", name);
}
int display_doctor() {
    FILE *file = fopen(DOCTOR_FILE, "r");
    if (file == NULL) {
        printf("Error opening file to read doctors!\n");
        return -1;
    }

    printf("\n=====================================================\n");
    printf("                  Display Doctors\n");
    printf("=====================================================\n");
    printf("List of Doctors:\n");
    printf("=====================================================\n");

    char line[256];
    int isFirstLine = 1;

    while (fgets(line, sizeof(line), file)) {

        if (isFirstLine) {
            isFirstLine = 0;
            continue;
        }

        int id, age, experience;
        char name[MAX_NAME_LEN], contactNumber[MAX_CONTACT_LEN], specialty[20];


        sscanf(line, "%d %[^ ] %d %[^ ] %d %s", &id, name, &age, contactNumber, &experience, specialty);


        printf("ID: %d\n", id);
        printf("Name: %s\n", name);
        printf("Age: %d\n", age);
        printf("Contact Number: %s\n", contactNumber);
        printf("Experience: %d years\n", experience);
        printf("Specialty: %s\n", specialty);
        printf("=====================================================\n");
    }

    fclose(file);
    return 0;
}

void addnurse() {
    Nurse new_node = (Nurse)malloc(sizeof(struct Nurse));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    int id;
    char name[MAX_NAME_LEN];
    char doctorAssigned[MAX_NAME_LEN];

    printf("Enter nurse's ID: ");
    scanf("%d", &id);
    printf("Enter nurse's name: ");
    scanf(" %[^\n]s", name);
    printf("Enter doctor assigned to the nurse: ");
    scanf(" %[^\n]s", doctorAssigned);

    new_node->id = id;
    strcpy(new_node->name, name);
    strcpy(new_node->doctorAssigned, doctorAssigned);
    new_node->next = NULL;

    if (headNurse == NULL) {
        headNurse = new_node;
    } else {
        Nurse temp = headNurse;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    FILE *file = fopen(NURSE_FILE, "a+");
    if (file) {
        fseek(file, 0, SEEK_END);
        long fileSize = ftell(file);
        if (fileSize == 0) {
            fprintf(file, "%s,%s,%s\n", "ID No.", "Name", "Doctor Assigned");
        }
        fprintf(file, "%d,%s,%s\n", id, name, doctorAssigned);
        fclose(file);
        printf("Nurse added successfully: Name: %s, Assigned Doctor: %s\n", name, doctorAssigned);
    } else {
        printf("Error opening file for writing!\n");
    }
}



void displaynurses() {
    printf("\n=====================================================\n");
    printf("                  List of Nurses\n");
    printf("\n=====================================================\n");

    FILE *file = fopen(NURSE_FILE, "r");
    if (file == NULL) {
        printf("No nurses available or error opening file!\n");
        return;
    }

    printf("%-10s %-30s %-30s\n", "ID No.", "Name", "Doctor Assigned");
    printf("-----------------------------------------------------\n");

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        int id;
        char name[MAX_NAME_LEN];
        char doctorAssigned[MAX_NAME_LEN];

        if (sscanf(line, "%d,%49[^,],%49[^\n]", &id, name, doctorAssigned) == 3) {
            printf("%-10d %-30s %-30s\n", id, name, doctorAssigned);
        }
    }

    fclose(file);
}


void addInventoryItem(int id, char* itemName, int quantity) {
    InventoryItem* newNode = (InventoryItem*)malloc(sizeof(InventoryItem));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->id = id;
    strcpy(newNode->itemName, itemName);
    newNode->quantity = quantity;
    newNode->next = NULL;

    if (inventoryHead == NULL) {
        inventoryHead = newNode;
    } else {
        InventoryItem* temp = inventoryHead;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Inventory item added successfully!\n");


    FILE* file = fopen(INVENTORY_FILE, "a");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        free(newNode);
        return;
    }


    fprintf(file, "%d,%s,%d\n", id, itemName, quantity);
    fclose(file);
}

void displayInventory() {
    printf("\n=====================================================\n");
    printf("                  Inventory List\n");
    printf("=====================================================\n");
    printf("%-10s %-30s %-10s\n", "ID", "Item Name", "Quantity");
    printf("-----------------------------------------------------\n");


    FILE *file = fopen(INVENTORY_FILE, "r");
    if (file == NULL) {
        printf("No inventory items available or error opening file!\n");
        return;
    }


    char line[256];
    while (fgets(line, sizeof(line), file)) {
        int id;
        char itemName[MAX_ITEM_NAME_LEN];
        int quantity;


        if (sscanf(line, "%d,%[^,],%d", &id, itemName, &quantity) == 3) {

            printf("%-10d %-30s %-10d\n", id, itemName, quantity);
        }
    }

    fclose(file);
}



void addPatient(int id, char* name) {

    Patient* newPatient = (Patient*)malloc(sizeof(Patient));
    if (newPatient == NULL) {
        printf("Memory allocation failed for new patient.\n");
        return;
    }
    newPatient->id = id;
    strcpy(newPatient->name, name);
    newPatient->totalBill = 0.0;
    newPatient->next = NULL;

    if (patientHead == NULL) {
        patientHead = newPatient;
    } else {
        Patient* temp = patientHead;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newPatient;
    }

    char specialtyNeeded[50];
    printf("Enter the required specialty: ");
    scanf(" %[^\n]", specialtyNeeded);


    char lowercase_specialty[50];
    strcpy(lowercase_specialty, specialtyNeeded);
    for (int i = 0; lowercase_specialty[i]; i++) {
        lowercase_specialty[i] = tolower(lowercase_specialty[i]);
    }

    FILE *patientFile = fopen(PATIENT_FILE, "a");
    if (patientFile) {
        fprintf(patientFile, "%-10d %-30s %-30s\n", id, name, specialtyNeeded);
        fclose(patientFile);
        printf("Patient added successfully.\n");
    } else {
        printf("Error opening patient file for writing!\n");
    }
}



void generateBill() {
    char patientName[50];
    float billAmount;

    printf("Enter Patient Name: ");
    scanf(" %[^\n]", patientName);
    printf("Enter Bill Amount: ");
    scanf("%f", &billAmount);

    Patient* current = patientHead;
    while (current != NULL) {
        if (strcmp(current->name, patientName) == 0) {
            current->totalBill += billAmount;
            printf("Bill generated for %s: Rs. %.2f\n", patientName, current->totalBill);
            return;
        }
        current = current->next;
    }

    printf("Patient not found.\n");
}

void viewTotalBill() {
    char patientName[50];
    printf("Enter Patient Name: ");
    scanf(" %[^\n]", patientName);

    Patient* current = patientHead;
    while (current != NULL) {
        if (strcmp(current->name, patientName) == 0) {
            printf("Total bill for %s: Rs. %.2f\n", patientName, current->totalBill);
            return;
        }
        current = current->next;
    }

    printf("Patient not found.\n");
}

void patientMenu() {
    int choice;

    while (1) {
        printf("\n=====================================================\n");
        printf("                 Patient Menu\n");
        printf("=====================================================\n");
        printf("1. Add Patient\n");
        printf("2. View Total Bill\n");
        printf("3. Exit to Main Menu\n");
        printf("=====================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int id;
                char name[50];
                printf("Enter Patient ID: ");
                scanf("%d", &id);
                printf("Enter Patient Name: ");
                scanf(" %[^\n]s", name);
                addPatient(id, name);
                break;
            }
            case 2:
                viewTotalBill();
                break;
            case 3:
                printf("Exiting to main menu...\n");
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}


void adminMenu() {
    int choice;

    while (1) {
        printf("\n====================================================\n");
        printf("    Admin Menu\n");
        printf("====================================================\n");
        printf("1. Manage Doctors\n");
        printf("2. Manage Nurses\n");
        printf("3. Manage Inventory\n");
        //printf("4. View Appointments\n");
        printf("4. Generate Bill\n");
        printf("5. Exit to Main Menu\n");
        printf("====================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    int doctorChoice;
                    printf("\n--- Manage Doctors ---\n");
                    printf("1. Add Doctor\n");
                    printf("2. Display Doctors\n");
                    printf("3. Delete Doctor\n");
                    printf("====================================================\n");
                    printf("Enter your choice: ");
                    scanf("%d", &doctorChoice);

                    switch (doctorChoice) {
                        case 1:
                            Add_Doctor();
                            break;
                        case 2:
                            display_doctor();
                            break;
                        case 3:
                            del_doctor();
                            break;
                        default:
                            printf("Invalid choice for managing doctors.\n");
                    }
                }
                break;

            case 2:
            {
                int nurseChoice;
                printf("\n--- Manage Nurses ---\n");
                printf("1. Add Nurse\n");
                printf("2. View Nurses\n");
                printf("====================================================\n");
                printf("Enter your choice: ");
                scanf("%d", &nurseChoice);

                switch (nurseChoice) {
                    case 1:
                        addnurse();
                        break;
                    case 2:
                        displaynurses();
                        break;
                    default:
                        printf("Invalid choice for managing nurses.\n");
                }
            }
            break;
                break;

            case 3:
{
    int inventoryChoice;
    printf("\n--- Manage Inventory ---\n");
    printf("1. Add Inventory Item\n");
    printf("2. View Inventory\n");
    printf("====================================================\n");
    printf("Enter your choice: ");
    scanf("%d", &inventoryChoice);

    switch (inventoryChoice) {
        case 1: {
            int id, quantity;
            char itemName[MAX_ITEM_NAME_LEN];
            printf("Enter Item ID: ");
            scanf("%d", &id);
            printf("Enter Item Name: ");
            scanf(" %[^\n]s", itemName);
            printf("Enter Item Quantity: ");
            scanf("%d", &quantity);
            addInventoryItem(id, itemName, quantity);
            break;
        }
        case 2:
            displayInventory();
            break;
        default:
            printf("Invalid choice for managing inventory.\n");
    }
    break;
}

                break;

           // case 4:  // View Appointments
             //   displayAppointments();
               // break;

            case 4:
                generateBill();
                break;

            case 5:
                printf("Exiting to main menu...\n");
                return;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}


struct User {
    char username[50];
    char password[50];
    struct User* left;
    struct User* right;
};


struct User* root = NULL;


struct User* createUserNode(char* username, char* password) {
    struct User* newUser = (struct User*)malloc(sizeof(struct User));
    strcpy(newUser->username, username);
    strcpy(newUser->password, password);
    newUser->left = newUser->right = NULL;
    return newUser;
}


struct User* insertUser(struct User* root, char* username, char* password) {
    if (root == NULL) {
        return createUserNode(username, password);
    }

    if (strcmp(username, root->username) < 0) {
        root->left = insertUser(root->left, username, password);
    } else if (strcmp(username, root->username) > 0) {
        root->right = insertUser(root->right, username, password);
    }

    return root;
}


struct User* searchUser(struct User* root, char* username) {
    if (root == NULL || strcmp(root->username, username) == 0) {
        return root;
    }

    if (strcmp(username, root->username) < 0) {
        return searchUser(root->left, username);
    }

    return searchUser(root->right, username);
}


void saveUsersToFile(struct User* root, FILE* file) {
    if (root == NULL) {
        return;
    }
    saveUsersToFile(root->left, file);
    fprintf(file, "%s %s\n", root->username, root->password);
    saveUsersToFile(root->right, file);
}


void loadUsersFromFile() {
    FILE* file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("No users to load from file.\n");
        return;
    }

    char username[50], password[50];
    while (fscanf(file, "%s %s", username, password) != EOF) {
        root = insertUser(root, username, password);
    }

    fclose(file);
}


void signup() {
    char username[50], password[50];

    printf("Enter a new username: ");
    scanf("%s", username);


    if (searchUser(root, username) != NULL) {
        printf("Username already taken. Please choose another one.\n");
        return;
    }

    printf("Enter a new password: ");
    scanf("%s", password);


    root = insertUser(root, username, password);


    FILE* file = fopen("users.txt", "w");
    if (file != NULL) {
        saveUsersToFile(root, file);
        fclose(file);
        printf("Signup successful! Please login to continue.\n");
    } else {
        printf("Error saving user data.\n");
    }
}

int login() {
    char username[50], password[50];
    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    struct User* user = searchUser(root, username);
    if (user != NULL && strcmp(user->password, password) == 0) {
        printf("Login successful!\n");
        return 1;
    } else {
        printf("Invalid username or password.\n");
        return 0;
    }
}

int main() {
    int mainChoice, loggedIn = 0;

    while (1) {
        printf("====================================================\n");
        printf("  Welcome to the Hospital Management System\n");
        printf("====================================================\n");
        printf("1. Signup\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("====================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &mainChoice);

        loadUsersFromFile();

        switch (mainChoice) {
            case 1:
                signup();
                break;
            case 2:
                loggedIn = login();
                if (loggedIn) {

                    while (1) {
                        printf("====================================================\n");
                        printf("  Hospital Management System\n");
                        printf("====================================================\n");
                        printf("1. Patient Menu\n");
                        printf("2. Admin Menu\n");
                        printf("3. Logout\n");
                        printf("====================================================\n");
                        printf("Enter your choice: ");
                        scanf("%d", &mainChoice);

                        switch (mainChoice) {
                            case 1:
                                patientMenu();
                                break;
                            case 2:
                                adminMenu();
                                break;
                            case 3:
                                printf("Logging out...\n\n");
                                loggedIn = 0;
                                break;
                            default:
                                printf("Invalid choice! Please try again.\n");
                        }
                        if (!loggedIn) {
                            break;
                        }
                    }
                }
                break;
            case 3:
                printf("Exiting the system...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
