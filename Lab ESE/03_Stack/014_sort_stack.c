#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stack {
    int arr[MAX];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

int peek(struct Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[s->top];
    }
    return -1;
}

void push(struct Stack *s, int value) {
    if (s->top < MAX - 1) {
        s->arr[++(s->top)] = value;
    }
}

int pop(struct Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[(s->top)--];
    }
    return -1;
}

void sortStack(struct Stack *s, int order) {
    struct Stack tempStack;
    initStack(&tempStack);
    int temp;

    while (!isEmpty(s)) {
        temp = pop(s);
        if (order == 2) {  // Descending order
            while (!isEmpty(&tempStack) && peek(&tempStack) > temp) {
                push(s, pop(&tempStack));
            }
        } else {  // Acsending order
            while (!isEmpty(&tempStack) && peek(&tempStack) < temp) {
                push(s, pop(&tempStack));
            }
        }
        push(&tempStack, temp);
    }

    while (!isEmpty(&tempStack)) {
        push(s, pop(&tempStack));
    }

    printf("Sorted Stack: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Stack s;
    initStack(&s);
    int choice, value, order;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check if Stack is Empty\n");
        printf("5. Sort Stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                value = pop(&s);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                value = peek(&s);
                if (value != -1) {
                    printf("Top element: %d\n", value);
                } else {
                    printf("Stack is empty\n");
                }
                break;
            case 4:
                if (isEmpty(&s)) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            case 5:
                printf("Choose sorting order:\n");
                printf("1. Ascending\n");
                printf("2. Descending\n");
                printf("Enter your choice: ");
                scanf("%d", &order);
                sortStack(&s, order);
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}



// Descending order
// #include <stdio.h>
// #include <stdlib.h>

// #define MAX 100

// struct Stack {
//     int arr[MAX];
//     int top;
// };

// void initStack(struct Stack *s) {
//     s->top = -1;
// }

// int isEmpty(struct Stack *s) {
//     return s->top == -1;
// }

// int peek(struct Stack *s) {
//     if (!isEmpty(s)) {
//         return s->arr[s->top];
//     }
//     return -1;
// }

// void push(struct Stack *s, int value) {
//     if (s->top < MAX - 1) {
//         s->arr[++(s->top)] = value;
//     }
// }

// int pop(struct Stack *s) {
//     if (!isEmpty(s)) {
//         return s->arr[(s->top)--];
//     }
//     return -1;
// }

// void sortStack(struct Stack *s) {
//     struct Stack tempStack;
//     initStack(&tempStack);

//     while (!isEmpty(s)) {
//         int temp = pop(s);
//         while (!isEmpty(&tempStack) && peek(&tempStack) > temp) {
//             push(s, pop(&tempStack));
//         }
//         push(&tempStack, temp);
//     }

//     while (!isEmpty(&tempStack)) {
//         push(s, pop(&tempStack));
//     }

//     printf("Sorted Stack: ");
//     for (int i = 0; i <= s->top; i++) {
//         printf("%d ", s->arr[i]);
//     }
//     printf("\n");
// }

// int main() {
//     struct Stack s;
//     initStack(&s);
//     int choice, value;

//     while (1) {
//         printf("\nMenu:\n");
//         printf("1. Push\n");
//         printf("2. Pop\n");
//         printf("3. Peek\n");
//         printf("4. Check if Stack is Empty\n");
//         printf("5. Sort Stack\n");
//         printf("6. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 printf("Enter value to push: ");
//                 scanf("%d", &value);
//                 push(&s, value);
//                 break;
//             case 2:
//                 value = pop(&s);
//                 if (value != -1) {
//                     printf("Popped value: %d\n", value);
//                 }
//                 break;
//             case 3:
//                 value = peek(&s);
//                 if (value != -1) {
//                     printf("Top element: %d\n", value);
//                 } else {
//                     printf("Stack is empty\n");
//                 }
//                 break;
//             case 4:
//                 if (isEmpty(&s)) {
//                     printf("Stack is empty\n");
//                 } else {
//                     printf("Stack is not empty\n");
//                 }
//                 break;
//             case 5:
//                 sortStack(&s);
//                 break;
//             case 6:
//                 printf("Exiting...\n");
//                 return 0;
//             default:
//                 printf("Invalid choice! Please try again.\n");
//         }
//     }

//     return 0;
// }
