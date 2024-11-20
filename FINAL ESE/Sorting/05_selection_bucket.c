#include <stdio.h>
#include <string.h>

struct Employee {
    char employee_name[50];
    int emp_no;
    float emp_salary;
};

void selectionSort(struct Employee arr[], int n, int *swapCount) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].emp_no < arr[minIndex].emp_no) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            struct Employee temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            (*swapCount)++;
        }
    }
}

void bucketSort(struct Employee arr[], int n, int *swapCount) {
    struct Employee buckets[10][n];
    int bucketCounts[10] = {0};
    int range = 1000;

    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i].emp_no / range;
        buckets[bucketIndex][bucketCounts[bucketIndex]++] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < bucketCounts[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j].emp_no > arr[j + 1].emp_no) {
                struct Employee temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*swapCount)++;
            }
        }
    }
}

int main() {
    int n, swapCount = 0;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee employees[n];
    for (int i = 0; i < n; i++) {
        printf("Enter employee name, emp_no, emp_salary for employee %d: ", i + 1);
        scanf("%s %d %f", employees[i].employee_name, &employees[i].emp_no, &employees[i].emp_salary);
    }

    selectionSort(employees, n, &swapCount);
    printf("Selection Sort performed %d swaps.\n", swapCount);

    swapCount = 0; // Reset swap count for Bucket Sort
    bucketSort(employees, n, &swapCount);
    printf("Bucket Sort performed %d swaps.\n", swapCount);

    return 0;
}
