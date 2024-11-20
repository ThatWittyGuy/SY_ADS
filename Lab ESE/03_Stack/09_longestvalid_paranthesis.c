#include <stdio.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int index) {
    if (top < MAX - 1) {
        stack[++top] = index;
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return -1;
}

int longestValidParentheses(char *s) {
    int maxLength = 0;
    push(-1);  // Push -1 to handle edge cases
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            push(i);  // Push the index of '('
        } else {
            pop();  // Pop the last '(' index
            if (top >= 0) {
                maxLength = (i - stack[top] > maxLength) ? (i - stack[top]) : maxLength;
            } else {
                push(i);  // Push the current index if stack is empty
            }
        }
    }
    return maxLength;
}

int main() {
    char s[MAX];
    
    printf("Enter the string containing only '(' and ')': ");
    scanf("%s", s);
    
    int result = longestValidParentheses(s);
    printf("Length of the longest valid parentheses: %d\n", result);
    
    return 0;
}
