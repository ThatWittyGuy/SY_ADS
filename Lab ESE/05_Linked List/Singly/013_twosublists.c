#include <stdio.h>
#include <stdlib.h>

void FrontBackSplit(int arr[], int n, int **front, int *front_size, int **back, int *back_size) {
    int mid = (n + 1) / 2;  // Determine the middle point (extra element in front for odd-length lists)
    
    *front_size = mid; // Front size is the first half or one extra element if odd
    *back_size = n - mid; // Back size is the remainder

    *front = (int*)malloc(*front_size * sizeof(int));
    *back = (int*)malloc(*back_size * sizeof(int));

    // Fill the front and back lists
    for (int i = 0; i < *front_size; i++) {
        (*front)[i] = arr[i];
    }
    for (int i = 0; i < *back_size; i++) {
        (*back)[i] = arr[*front_size + i];
    }
}

void printList(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int *front, *back, front_size, back_size;

    FrontBackSplit(arr, n, &front, &front_size, &back, &back_size);

    printf("Front list: ");
    printList(front, front_size);
    printf("\n");

    printf("Back list: ");
    printList(back, back_size);
    printf("\n");

    // Free the dynamically allocated memory
    free(front);
    free(back);

    return 0;
}
