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
    if (c == '^')
        return 3;
    return 0;
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void infixToPostfix(char *infix, char *postfix)
{
    int k = 0;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        char c = infix[i];
        if (isalnum(c))
        {
            postfix[k++] = c;
        }
        else if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            while (top != -1 && stack[top] != '(')
                postfix[k++] = pop();
            pop();
        }
        else if (isOperator(c))
        {
            while (top != -1 && precedence(stack[top]) >= precedence(c) && !(c == '^' && stack[top] == '^'))
                postfix[k++] = pop();
            push(c);
        }
    }
    while (top != -1)
        postfix[k++] = pop();
    postfix[k] = '\0';
}

void infixToPrefix(char *infix, char *prefix)
{
    int len = strlen(infix);
    char reversed[MAX];
    
    for (int i = 0; i < len; i++)
    {
        if (infix[i] == '(')
            reversed[len - i - 1] = ')';
        else if (infix[i] == ')')
            reversed[len - i - 1] = '(';
        else
            reversed[len - i - 1] = infix[i];
    }
    reversed[len] = '\0';

    char postfix[MAX];
    infixToPostfix(reversed, postfix);

    int postLen = strlen(postfix);
    for (int i = 0; i < postLen; i++)
    {
        prefix[i] = postfix[postLen - i - 1];
    }
    prefix[postLen] = '\0';
}

int main()
{
    char infix[MAX], postfix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}
