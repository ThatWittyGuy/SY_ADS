#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    char* arr[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, char* name) {
    if (stack->top < MAX_SIZE - 1) {
        stack->arr[++stack->top] = name;
    }
}

char* pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top--];
    }
    return NULL;
}

int main() {
    Stack stack;
    initialize(&stack);

    char input[MAX_SIZE];
    char *firstName, *middleName, *surname;

    printf("Enter your First Name, Middle Name, and Surname (separated by spaces): ");
    fgets(input, MAX_SIZE, stdin);
    
    input[strcspn(input, "\n")] = 0;

    firstName = strtok(input, " ");
    middleName = strtok(NULL, " ");
    surname = strtok(NULL, " ");

    push(&stack, surname);
    push(&stack, firstName);
    push(&stack, middleName);

    printf("Rearranged Names: \n");
    printf("%s %s %s\n", pop(&stack), pop(&stack), pop(&stack));

    return 0;
}
