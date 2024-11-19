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
            sprintf(temp, "%c%s%s", c, op1, op2);
            push(temp);
        }
    }
    strcpy(prefix, pop());
}

int main()
{
    char postfix[MAX], prefix[MAX];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    postfixToPrefix(postfix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
