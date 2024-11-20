#include <stdio.h>
#include <string.h>

struct Student {
    char student_name[50];
    int student_roll_no;
    int total_marks;
};

void swap(struct Student *a, struct Student *b, int *swapCount) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
    (*swapCount)++;
}

void printStudents(struct Student arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Roll No: %d, Marks: %d\n", arr[i].student_name, arr[i].student_roll_no, arr[i].total_marks);
    }
    printf("\n");
}

void insertionSort(struct Student arr[], int n, int *swapCount) {
    for (int i = 1; i < n; i++) {
        struct Student key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].student_roll_no > key.student_roll_no) {
            arr[j + 1] = arr[j];
            j--;
            (*swapCount)++;
        }
        arr[j + 1] = key;
    }
}

int partition(struct Student arr[], int low, int high, int *swapCount) {
    int pivot = arr[high].student_roll_no;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].student_roll_no < pivot) {
            i++;
            swap(&arr[i], &arr[j], swapCount);
        }
    }
    swap(&arr[i + 1], &arr[high], swapCount);
    return i + 1;
}

void quickSort(struct Student arr[], int low, int high, int *swapCount) {
    if (low < high) {
        int pi = partition(arr, low, high, swapCount);
        quickSort(arr, low, pi - 1, swapCount);
        quickSort(arr, pi + 1, high, swapCount);
    }
}

int main() {
    int n, swapCount = 0;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student students[n];
    for (int i = 0; i < n; i++) {
        printf("Enter student name, roll no, total marks for student %d: ", i + 1);
        scanf("%s %d %d", students[i].student_name, &students[i].student_roll_no, &students[i].total_marks);
    }

    // Perform Insertion Sort
    swapCount = 0;
    insertionSort(students, n, &swapCount);
    printf("\nInsertion Sort performed %d swaps.\n", swapCount);
    printStudents(students, n);

    // Perform Quick Sort
    swapCount = 0;
    quickSort(students, 0, n - 1, &swapCount);
    printf("\nQuick Sort performed %d swaps.\n", swapCount);
    printStudents(students, n);

    return 0;
}
