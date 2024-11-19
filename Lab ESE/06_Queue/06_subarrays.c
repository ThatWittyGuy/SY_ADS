#include <stdio.h>

void divideArray(int arr[], int n, int m)
{
    int size = n / m;
    int remainder = n % m;
    int queueStart = 0;

    for (int i = 0; i < m; i++)
    {
        int currentSize = size + (i < remainder ? 1 : 0);
        printf("Queue %d: ", i + 1);
        for (int j = 0; j < currentSize; j++)
        {
            printf("%d ", arr[queueStart + j]);
        }
        printf("\n");
        queueStart += currentSize;
    }
}

int main()
{
    int n, m;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the number of subarrays (m): ");
    scanf("%d", &m);

    int arr[n];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    divideArray(arr, n, m);

    return 0;
}
