#include <stdio.h>
#include <string.h>

struct Employee {
    char employee_name[50];
    int emp_no;
    float emp_salary;
};

void swap(struct Employee *a, struct Employee *b, int *swapCount) {
    struct Employee temp = *a;
    *a = *b;
    *b = temp;
    (*swapCount)++;
}

void printEmployees(struct Employee arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Emp No: %d, Salary: %.2f\n", arr[i].employee_name, arr[i].emp_no, arr[i].emp_salary);
    }
    printf("\n");
}

void bubbleSort(struct Employee arr[], int n, int *swapCount) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j].emp_no > arr[j + 1].emp_no) {
                swap(&arr[j], &arr[j + 1], swapCount);
            }
        }
    }
}

void heapify(struct Employee arr[], int n, int i, int *swapCount) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].emp_no > arr[largest].emp_no)
        largest = left;
    if (right < n && arr[right].emp_no > arr[largest].emp_no)
        largest = right;
    if (largest != i) {
        swap(&arr[i], &arr[largest], swapCount);
        heapify(arr, n, largest, swapCount);
    }
}

void heapSort(struct Employee arr[], int n, int *swapCount) {
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
    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee employees[n];
    for (int i = 0; i < n; i++) {
        printf("Enter employee name, emp_no, emp_salary for employee %d: ", i + 1);
        scanf("%s %d %f", employees[i].employee_name, &employees[i].emp_no, &employees[i].emp_salary);
    }

    swapCount = 0;
    bubbleSort(employees, n, &swapCount);
    printf("\nBubble Sort performed %d swaps.\n", swapCount);
    printEmployees(employees, n);

    swapCount = 0;
    heapSort(employees, n, &swapCount);
    printf("\nHeap Sort performed %d swaps.\n", swapCount);
    printEmployees(employees, n);

    return 0;
}