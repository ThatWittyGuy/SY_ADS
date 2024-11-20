#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    } else {
        printf("Stack Overflow\n");
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack Underflow\n");
        return -1;
    }
}

void factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        push(i);
    }
    while (top >= 0) {
        result *= pop();
    }
    printf("Factorial of %d is %d\n", n, result);
}

void fibonacci(int n) {
    if (n <= 0) return;
    push(0);
    if (n > 1) push(1);
    printf("Fibonacci Series: 0 ");
    if (n > 1) printf("1 ");
    for (int i = 2; i < n; i++) {
        int a = pop();
        int b = stack[top];
        push(a);
        int next = a + b;
        push(next);
        printf("%d ", next);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Calculate Factorial\n");
        printf("2. Generate Fibonacci Series\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to calculate factorial: ");
                scanf("%d", &value);
                factorial(value);
                break;
            case 2:
                printf("Enter the number of terms for Fibonacci series: ");
                scanf("%d", &value);
                fibonacci(value);
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
