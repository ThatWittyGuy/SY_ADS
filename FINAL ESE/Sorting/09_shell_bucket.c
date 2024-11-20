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

void shellSort(struct Employee arr[], int n, int *swapCount) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            struct Employee temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap].emp_no > temp.emp_no; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
            if (j != i) (*swapCount)++;
        }
    }
}

void bucketSort(struct Employee arr[], int n, int *swapCount) {
    int max = arr[0].emp_no;
    for (int i = 1; i < n; i++) {
        if (arr[i].emp_no > max) max = arr[i].emp_no;
    }
    
    int bucketSize = max / 10 + 1;
    struct Employee buckets[bucketSize][n];
    int bucketCount[bucketSize];
    
    for (int i = 0; i < bucketSize; i++) bucketCount[i] = 0;
    
    for (int i = 0; i < n; i++) {
        int index = arr[i].emp_no / 10;
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
            if (arr[j].emp_no > arr[j + 1].emp_no) {
                swap(&arr[j], &arr[j + 1], swapCount);
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

    swapCount = 0;
    shellSort(employees, n, &swapCount);
    printf("\nShell Sort performed %d swaps.\n", swapCount);
    printEmployees(employees, n);

    swapCount = 0;
    bucketSort(employees, n, &swapCount);
    printf("\nBucket Sort performed %d swaps.\n", swapCount);
    printEmployees(employees, n);

    return 0;
}
