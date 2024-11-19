#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void reverse(char *exp)
{
    int length = strlen(exp);
    for (int i = 0; i < length / 2; i++)
    {
        char temp = exp[i];
        exp[i] = exp[length - i - 1];
        exp[length - i - 1] = temp;
    }
}

void infixToPrefix(char *infix, char *prefix)
{
    reverse(infix);
    int i = 0, k = 0;
    char c;

    while ((c = infix[i++]) != '\0')
    {
        if (isalnum(c))
        {
            prefix[k++] = c;
        }
        else if (c == ')')
        {
            push(c);
        }
        else if (c == '(')
        {
            while (top != -1 && stack[top] != ')')
                prefix[k++] = pop();
            pop();
        }
        else if (isOperator(c))
        {
            while (top != -1 && precedence(stack[top]) > precedence(c))
                prefix[k++] = pop();
            push(c);
        }
    }

    while (top != -1)
        prefix[k++] = pop();

    prefix[k] = '\0';
    reverse(prefix);
}

int main()
{
    char infix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
