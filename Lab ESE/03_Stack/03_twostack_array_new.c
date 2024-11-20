#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int arr[MAX];
int top1 = -1, top2 = MAX;

void push1(int value) {
    if (top1 < top2 - 1) {
        arr[++top1] = value;
    } else {
        printf("Stack 1 is full\n");
    }
}

void push2(int value) {
    if (top1 < top2 - 1) {
        arr[--top2] = value;
    } else {
        printf("Stack 2 is full\n");
    }
}

int pop1() {
    if (top1 >= 0) {
        return arr[top1--];
    } else {
        printf("Stack 1 is empty\n");
        return -1;
    }
}

int pop2() {
    if (top2 < MAX) {
        return arr[top2++];
    } else {
        printf("Stack 2 is empty\n");
        return -1;
    }
}

int stackFull() {
    return top1 >= top2 - 1;
}

int stackEmpty1() {
    return top1 == -1;
}

int stackEmpty2() {
    return top2 == MAX;
}

void display1() {
    if (top1 == -1) {
        printf("Stack 1 is empty\n");
    } else {
        printf("Stack 1 elements: ");
        for (int i = 0; i <= top1; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

void display2() {
    if (top2 == MAX) {
        printf("Stack 2 is empty\n");
    } else {
        printf("Stack 2 elements: ");
        for (int i = MAX - 1; i >= top2; i--) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push to Stack 1\n");
        printf("2. Push to Stack 2\n");
        printf("3. Pop from Stack 1\n");
        printf("4. Pop from Stack 2\n");
        printf("5. Check if Stack 1 is full\n");
        printf("6. Check if Stack 2 is full\n");
        printf("7. Check if Stack 1 is empty\n");
        printf("8. Check if Stack 2 is empty\n");
        printf("9. Display Stack 1\n");
        printf("10. Display Stack 2\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push to Stack 1: ");
                scanf("%d", &value);
                push1(value);
                break;
            case 2:
                printf("Enter value to push to Stack 2: ");
                scanf("%d", &value);
                push2(value);
                break;
            case 3:
                value = pop1();
                if (value != -1) {
                    printf("Popped from Stack 1: %d\n", value);
                }
                break;
            case 4:
                value = pop2();
                if (value != -1) {
                    printf("Popped from Stack 2: %d\n", value);
                }
                break;
            case 5:
                if (stackFull()) {
                    printf("Both stacks are full\n");
                } else {
                    printf("Both stacks are not full\n");
                }
                break;
            case 6:
                if (stackFull()) {
                    printf("Both stacks are full\n");
                } else {
                    printf("Both stacks are not full\n");
                }
                break;
            case 7:
                if (stackEmpty1()) {
                    printf("Stack 1 is empty\n");
                } else {
                    printf("Stack 1 is not empty\n");
                }
                break;
            case 8:
                if (stackEmpty2()) {
                    printf("Stack 2 is empty\n");
                } else {
                    printf("Stack 2 is not empty\n");
                }
                break;
            case 9:
                display1();
                break;
            case 10:
                display2();
                break;
            case 11:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
