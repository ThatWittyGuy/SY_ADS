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

void merge(struct Faculty arr[], int left, int mid, int right, int *swapCount) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    struct Faculty L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].faculty_ID <= R[j].faculty_ID) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(struct Faculty arr[], int left, int right, int *swapCount) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, swapCount);
        mergeSort(arr, mid + 1, right, swapCount);
        merge(arr, left, mid, right, swapCount);
    }
}

void heapify(struct Faculty arr[], int n, int i, int *swapCount) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].faculty_ID > arr[largest].faculty_ID)
        largest = left;
    if (right < n && arr[right].faculty_ID > arr[largest].faculty_ID)
        largest = right;
    if (largest != i) {
        swap(&arr[i], &arr[largest], swapCount);
        heapify(arr, n, largest, swapCount);
    }
}

void heapSort(struct Faculty arr[], int n, int *swapCount) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, swapCount);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i], swapCount);
        heapify(arr, i, 0, swapCount);
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
    mergeSort(faculties, 0, n - 1, &swapCount);
    printf("\nMerge Sort performed %d swaps.\n", swapCount);
    printFaculty(faculties, n);

    swapCount = 0;
    heapSort(faculties, n, &swapCount);
    printf("\nHeap Sort performed %d swaps.\n", swapCount);
    printFaculty(faculties, n);

    return 0;
}
