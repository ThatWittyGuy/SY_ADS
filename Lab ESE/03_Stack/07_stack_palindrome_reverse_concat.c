#include <stdio.h>
#include <string.h>

#define MAX 100

// Stack structure
typedef struct {
    char data[MAX];
    int top;
} Stack;

// Stack functions
void initStack(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int isFull(Stack* s) {
    return s->top == MAX - 1;
}

void push(Stack* s, char val) {
    if (!isFull(s)) {
        s->data[++(s->top)] = val;
    } else {
        printf("Stack overflow\n");
    }
}

char pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    } else {
        printf("Stack underflow\n");
        return '\0';
    }
}

char top(Stack* s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    } else {
        return '\0';  // Stack is empty
    }
}

// Function to check if a string is a palindrome using stack
int isPalindrome(char* s) {
    Stack stack;
    initStack(&stack);
    int length = strlen(s);

    for (int i = 0; i < length; i++) {
        push(&stack, s[i]);
    }

    for (int i = 0; i < length; i++) {
        if (s[i] != pop(&stack)) {
            return 0; // Not a palindrome
        }
    }

    return 1; // Palindrome
}

// Function to reverse a string using stack
void reverseString(char* s, char* reversed) {
    Stack stack;
    initStack(&stack);
    int length = strlen(s);

    for (int i = 0; i < length; i++) {
        push(&stack, s[i]);
    }

    for (int i = 0; i < length; i++) {
        reversed[i] = pop(&stack);
    }
    reversed[length] = '\0'; // Null-terminate the reversed string
}

// Function to concatenate two strings using stack
void concatStrings(char* s1, char* s2, char* result) {
    Stack stack;
    initStack(&stack);
    int i = 0;

    // Push first string onto stack
    while (s1[i] != '\0') {
        push(&stack, s1[i]);
        i++;
    }

    // Push second string onto stack
    i = 0;
    while (s2[i] != '\0') {
        push(&stack, s2[i]);
        i++;
    }

    // Pop all elements into result string
    i = 0;
    while (!isEmpty(&stack)) {
        result[i++] = pop(&stack);
    }
    result[i] = '\0'; // Null-terminate the concatenated string
}

// Function to compare two strings using stack
int compareStrings(char* s1, char* s2) {
    Stack stack1, stack2;
    initStack(&stack1);
    initStack(&stack2);
    int i = 0;

    while (s1[i] != '\0') {
        push(&stack1, s1[i]);
        i++;
    }

    i = 0;
    while (s2[i] != '\0') {
        push(&stack2, s2[i]);
        i++;
    }

    // Compare characters from both stacks
    while (!isEmpty(&stack1) && !isEmpty(&stack2)) {
        if (pop(&stack1) != pop(&stack2)) {
            return 0; // Strings are not equal
        }
    }

    // If both stacks are empty, strings are equal
    if (isEmpty(&stack1) && isEmpty(&stack2)) {
        return 1; // Strings are equal
    } else {
        return 0; // Strings are not equal
    }
}

int main() {
    char s1[MAX], s2[MAX], reversed[MAX], concatResult[MAX];

    printf("Enter a string: ");
    scanf("%s", s1);

    printf("Enter another string for concat and compare: ");
    scanf("%s", s2);

    // A. Palindrome Check
    if (isPalindrome(s1)) {
        printf("A. Palindrome: Yes\n");
    } else {
        printf("A. Palindrome: No\n");
    }

    // B. Reverse String
    reverseString(s1, reversed);
    printf("B. Reverse: %s\n", reversed);

    // C. Concatenate Strings
    concatStrings(s1, s2, concatResult);
    printf("C. Concat: %s\n", concatResult);

    // D. Compare Strings
    if (compareStrings(s1, s2)) {
        printf("D. Compare: Strings are equal\n");
    } else {
        printf("D. Compare: Strings are not equal\n");
    }

    return 0;
}
