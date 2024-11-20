#include <stdio.h>

void findSwappedElements(int arr[], int n) {
    int x = -1, y = -1;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            y = arr[i];
            if (x == -1) {
                x = arr[i + 1];
            }
        }
    }

    printf("Swapped elements are: %d and %d\n", x, y);
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted elements with two swapped: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findSwappedElements(arr, n);

    return 0;
}
