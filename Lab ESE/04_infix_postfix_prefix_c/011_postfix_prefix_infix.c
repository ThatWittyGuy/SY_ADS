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
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void postfixToPrefix(char *postfix, char *prefix)
{
    int len = strlen(postfix);
    for (int i = 0; i < len; i++)
    {
        char c = postfix[i];
        if (isalnum(c))
        {
            char temp[2] = {c, '\0'};
            push(temp);
        }
        else if (isOperator(c))
        {
            char *op2 = pop();
            char *op1 = pop();
            char temp[MAX];
            if (c == '^')
            {
                sprintf(temp, "%c%s%s", c, op1, op2);
            }
            else
            {
                sprintf(temp, "%c%s%s", c, op1, op2);
            }
            push(temp);
        }
    }
    strcpy(prefix, pop());
}

void postfixToInfix(char *postfix, char *infix)
{
    int len = strlen(postfix);
    for (int i = 0; i < len; i++)
    {
        char c = postfix[i];
        if (isalnum(c))
        {
            char temp[2] = {c, '\0'};
            push(temp);
        }
        else if (isOperator(c))
        {
            char *op2 = pop();
            char *op1 = pop();
            char temp[MAX];
            sprintf(temp, "(%s%c%s)", op1, c, op2);
            push(temp);
        }
    }
    strcpy(infix, pop());
}

int main()
{
    char postfix[MAX], prefix[MAX], infix[MAX];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    postfixToPrefix(postfix, prefix);
    printf("Prefix expression: %s\n", prefix);

    postfixToInfix(postfix, infix);
    printf("Infix expression: %s\n", infix);

    return 0;
}
