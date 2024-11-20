#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return -1;
}

void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }
    for (int i = 0; i < len; i++) {
        str[i] = pop();
    }
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    scanf("%s", str);

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}


// Palindrome check also

// #include <stdio.h>
// #include <string.h>

// #define MAX 100

// char stack[MAX];
// int top = -1;

// void push(char c) {
//     if (top < MAX - 1) {
//         stack[++top] = c;
//     }
// }

// char pop() {
//     if (top >= 0) {
//         return stack[top--];
//     }
//     return -1;
// }

// void reverseString(char *str) {
//     int len = strlen(str);
//     for (int i = 0; i < len; i++) {
//         push(str[i]);
//     }
//     for (int i = 0; i < len; i++) {
//         str[i] = pop();
//     }
// }

// int isPalindrome(char *str) {
//     char original[MAX];
//     strcpy(original, str);  // Save original string for comparison

//     reverseString(str);  // Reverse the string

//     if (strcmp(original, str) == 0) {
//         return 1;  // Palindrome
//     }
//     return 0;  // Not a palindrome
// }

// int main() {
//     char str[MAX];

//     printf("Enter a string: ");
//     scanf("%s", str);

//     if (isPalindrome(str)) {
//         printf("The string is a palindrome.\n");
//     } else {
//         printf("The string is not a palindrome.\n");
//     }

//     return 0;
// }
