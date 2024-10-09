#include <stdio.h>
int iterations = 0;
int swaps = 0;
void quick_sort(int arr[], int low, int high) {
    int i, j, pivot, temp;
    if (low < high) {
        pivot = arr[high];
        i = low - 1;
        for (j = low; j < high; j++) {
            iterations++;
            if (arr[j] < pivot) {
                i++;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                swaps++;
            }
        }
        temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        swaps++;
        quick_sort(arr, low, i);
        quick_sort(arr, i + 2, high);
    }
}
int main() {
    int arr[] = {55, 2, 32, 43, 15, 6, 77};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    quick_sort(arr, 0, n - 1);
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nIterations = %d\n", iterations);
    printf("Swaps = %d\n", swaps);
    return 0;
}
