#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char *str)
{
    if (top < MAX - 1)
        strcpy(stack[++top], str);
}

char *pop()
{
    if (top >= 0)
        return stack[top--];
    return NULL;
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void prefixToInfix(char *prefix, char *infix)
{
    int len = strlen(prefix);
    for (int i = len - 1; i >= 0; i--)
    {
        char c = prefix[i];
        if (isalnum(c))
        {
            char temp[2] = {c, '\0'};
            push(temp);
        }
        else if (isOperator(c))
        {
            char *op1 = pop();
            char *op2 = pop();
            char temp[MAX];
            sprintf(temp, "(%s%c%s)", op1, c, op2);
            push(temp);
        }
    }
    strcpy(infix, pop());
}

int main()
{
    char prefix[MAX], infix[MAX];

    printf("Enter prefix expression: ");
    scanf("%s", prefix);

    prefixToInfix(prefix, infix);

    printf("Infix expression: %s\n", infix);

    return 0;
}
