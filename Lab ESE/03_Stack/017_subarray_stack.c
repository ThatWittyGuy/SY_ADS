#include <stdio.h>

void push(int arr[], int *top, int stack[], int m, int n) {
    if (*top < n - 1) {
        stack[*top] = arr[*top];
        (*top)++;
    }
    else {
        printf("Stack overflow\n");
    }
}

int main() {
    int n, m;
    printf("Enter size of the array: ");
    scanf("%d", &n);
    printf("Enter number of stacks (m, where 2 < m < n): ");
    scanf("%d", &m);
    
    if (m <= 2 || m >= n) {
        printf("Invalid number of stacks\n");
        return 0;
    }

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int subsize = n / m; // size of each stack
    int remainder = n % m; // remaining elements
    
    int stacks[m][subsize + (remainder > 0 ? 1 : 0)];
    int tops[m];
    
    for (int i = 0; i < m; i++) {
        tops[i] = 0;
    }
    
    int idx = 0;
    
    for (int i = 0; i < m; i++) {
        int limit = subsize;
        if (remainder > 0) {
            limit++;
            remainder--;
        }
        
        for (int j = 0; j < limit; j++) {
            if (idx < n) {
                stacks[i][tops[i]] = arr[idx++];
                tops[i]++;
            }
        }
    }

    printf("Stacks after dividing the array:\n");
    for (int i = 0; i < m; i++) {
        printf("Stack %d: ", i + 1);
        for (int j = 0; j < tops[i]; j++) {
            printf("%d ", stacks[i][j]);
        }
        printf("\n");
    }

    return 0;
}
