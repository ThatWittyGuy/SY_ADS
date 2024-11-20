#include <stdio.h>
#include <string.h>

struct Faculty {
    char faculty_name[50];
    int faculty_ID;
    char subject_codes[10];
    char class_names[50];
};

void swap(struct Faculty *a, struct Faculty *b, int *swapCount) {
    struct Faculty temp = *a;
    *a = *b;
    *b = temp;
    (*swapCount)++;
}

void printFaculty(struct Faculty arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Faculty ID: %d, Subjects: %s, Classes: %s\n", arr[i].faculty_name, arr[i].faculty_ID, arr[i].subject_codes, arr[i].class_names);
    }
    printf("\n");
}

void bucketSort(struct Faculty arr[], int n, int *swapCount) {
    int max = arr[0].faculty_ID;
    for (int i = 1; i < n; i++) {
        if (arr[i].faculty_ID > max) max = arr[i].faculty_ID;
    }
    
    int bucketSize = max / 10 + 1;
    struct Faculty buckets[bucketSize][n];
    int bucketCount[bucketSize];
    
    for (int i = 0; i < bucketSize; i++) bucketCount[i] = 0;
    
    for (int i = 0; i < n; i++) {
        int index = arr[i].faculty_ID / 10;
        buckets[index][bucketCount[index]++] = arr[i];
    }
    
    int index = 0;
    for (int i = 0; i < bucketSize; i++) {
        for (int j = 0; j < bucketCount[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j].faculty_ID > arr[j + 1].faculty_ID) {
                swap(&arr[j], &arr[j + 1], swapCount);
            }
        }
    }
}

int partition(struct Faculty arr[], int low, int high, int *swapCount) {
    int pivot = arr[high].faculty_ID;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].faculty_ID < pivot) {
            i++;
            swap(&arr[i], &arr[j], swapCount);
        }
    }
    swap(&arr[i + 1], &arr[high], swapCount);
    return i + 1;
}

void quickSort(struct Faculty arr[], int low, int high, int *swapCount) {
    if (low < high) {
        int pi = partition(arr, low, high, swapCount);
        quickSort(arr, low, pi - 1, swapCount);
        quickSort(arr, pi + 1, high, swapCount);
    }
}

int main() {
    int n, swapCount = 0;
    printf("Enter number of faculty members: ");
    scanf("%d", &n);

    struct Faculty faculties[n];
    for (int i = 0; i < n; i++) {
        printf("Enter faculty name, faculty_ID, subject_codes, class_names for faculty %d: ", i + 1);
        scanf("%s %d %s %s", faculties[i].faculty_name, &faculties[i].faculty_ID, faculties[i].subject_codes, faculties[i].class_names);
    }

    swapCount = 0;
    bucketSort(faculties, n, &swapCount);
    printf("\nBucket Sort performed %d swaps.\n", swapCount);
    printFaculty(faculties, n);

    swapCount = 0;
    quickSort(faculties, 0, n - 1, &swapCount);
    printf("\nQuick Sort performed %d swaps.\n", swapCount);
    printFaculty(faculties, n);

    return 0;
}
