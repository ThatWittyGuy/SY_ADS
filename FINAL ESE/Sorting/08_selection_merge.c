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

void selectionSort(struct Student arr[], int n, int *swapCount) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].student_roll_no < arr[minIndex].student_roll_no) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(&arr[i], &arr[minIndex], swapCount);
        }
    }
}

void merge(struct Student arr[], int left, int mid, int right, int *swapCount) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    struct Student L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].student_roll_no <= R[j].student_roll_no) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(struct Student arr[], int left, int right, int *swapCount) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, swapCount);
        mergeSort(arr, mid + 1, right, swapCount);
        merge(arr, left, mid, right, swapCount);
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

    // Perform Selection Sort
    swapCount = 0;
    selectionSort(students, n, &swapCount);
    printf("\nSelection Sort performed %d swaps.\n", swapCount);
    printStudents(students, n);

    // Perform Merge Sort
    swapCount = 0;
    mergeSort(students, 0, n - 1, &swapCount);
    printf("\nMerge Sort performed %d swaps.\n", swapCount);
    printStudents(students, n);

    return 0;
}
