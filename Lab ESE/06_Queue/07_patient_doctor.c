#include <stdio.h>
#include <string.h>

#define MAX_PATIENTS 100
#define MAX_DOCTORS 5

struct Patient
{
    char name[50];
    int patientID;
};

struct Queue
{
    struct Patient patients[MAX_PATIENTS];
    int front, rear;
};

void initQueue(struct Queue *q)
{
    q->front = q->rear = -1;
}

int isQueueEmpty(struct Queue *q)
{
    return q->front == -1;
}

int isQueueFull(struct Queue *q)
{
    return q->rear == MAX_PATIENTS - 1;
}

void enqueue(struct Queue *q, struct Patient p)
{
    if (isQueueFull(q))
    {
        printf("Queue is full. Cannot add more patients.\n");
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->patients[++(q->rear)] = p;
}

struct Patient dequeue(struct Queue *q)
{
    struct Patient p = {"", 0};
    if (isQueueEmpty(q))
    {
        printf("Queue is empty. No patients to assign.\n");
        return p;
    }
    p = q->patients[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front++;
    }
    return p;
}

void checkInPatient(struct Queue *q, struct Patient patients[], int *patientCount)
{
    struct Patient newPatient;
    printf("Enter patient name: ");
    scanf("%s", newPatient.name);
    newPatient.patientID = ++(*patientCount);
    enqueue(q, newPatient);
    printf("Patient %s checked in. Patient ID: %d\n", newPatient.name, newPatient.patientID);
}

void assignPatientToDoctor(struct Queue *q, struct Doctor doctors[], int doctorCount)
{
    for (int i = 0; i < doctorCount; i++)
    {
        if (doctors[i].assignedPatientID == 0)
        {
            if (!isQueueEmpty(q))
            {
                struct Patient p = dequeue(q);
                doctors[i].assignedPatientID = p.patientID;
                printf("Doctor %s is assigned to Patient %s (ID: %d)\n", doctors[i].name, p.name, p.patientID);
                return;
            }
        }
    }
    printf("All doctors are busy. No available doctors at the moment.\n");
}

void showDoctorsStatus(struct Doctor doctors[], int doctorCount)
{
    for (int i = 0; i < doctorCount; i++)
    {
        if (doctors[i].assignedPatientID != 0)
        {
            printf("Doctor %s is assigned to Patient ID %d\n", doctors[i].name, doctors[i].assignedPatientID);
        }
        else
        {
            printf("Doctor %s is available\n", doctors[i].name);
        }
    }
}

struct Doctor
{
    char name[50];
    int assignedPatientID;
};

int main()
{
    struct Patient patients[MAX_PATIENTS];
    struct Doctor doctors[MAX_DOCTORS] = {
        {"Dr. Smith", 0},
        {"Dr. Johnson", 0},
        {"Dr. Lee", 0},
        {"Dr. Brown", 0},
        {"Dr. Williams", 0}};
    struct Queue patientQueue;
    initQueue(&patientQueue);
    int patientCount = 0;
    int choice;

    while (1)
    {
        printf("\n1. Check-in Patient\n2. Assign Patient to Doctor\n3. Show Doctors' Status\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            checkInPatient(&patientQueue, patients, &patientCount);
        }
        else if (choice == 2)
        {
            assignPatientToDoctor(&patientQueue, doctors, MAX_DOCTORS);
        }
        else if (choice == 3)
        {
            showDoctorsStatus(doctors, MAX_DOCTORS);
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
