#include <stdio.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c)
{
    if (top < MAX - 1)
        stack[++top] = c;
}

char pop()
{
    if (top >= 0)
        return stack[top--];
    return -1;
}

int isValid(char *expr)
{
    for (int i = 0; expr[i] != '\0'; i++)
    {
        char c = expr[i];
        if (c == '(' || c == '{' || c == '[')
            push(c);
        else if (c == ')' || c == '}' || c == ']')
        {
            if (top == -1)
                return 0;
            char topChar = pop();
            if ((c == ')' && topChar != '(') || (c == '}' && topChar != '{') || (c == ']' && topChar != '['))
                return 0;
        }
    }
    return top == -1;
}

int main()
{
    char expr[MAX];

    printf("Enter a string of parentheses: ");
    scanf("%s", expr);

    if (isValid(expr))
        printf("The parentheses are valid.\n");
    else
        printf("The parentheses are invalid.\n");

    return 0;
}
