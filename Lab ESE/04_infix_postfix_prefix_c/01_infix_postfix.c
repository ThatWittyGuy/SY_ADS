// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>

// #define MAX 100

// char stack[MAX];
// int top = -1;

// void push(char c)
// {
//     if (top < MAX - 1)
//         stack[++top] = c;
// }

// char pop()
// {
//     if (top >= 0)
//         return stack[top--];
//     return -1;
// }

// int precedence(char c)
// {
//     if (c == '+' || c == '-')
//         return 1;
//     if (c == '*' || c == '/')
//         return 2;
//     return 0;
// }

// int isOperator(char c)
// {
//     return (c == '+' || c == '-' || c == '*' || c == '/');
// }

// void infixToPostfix(char *infix, char *postfix)
// {
//     int i = 0, k = 0;
//     char c;

//     while ((c = infix[i++]) != '\0')
//     {
//         if (isalnum(c))
//         {
//             postfix[k++] = c;
//         }
//         else if (c == '(')
//         {
//             push(c);
//         }
//         else if (c == ')')
//         {
//             while (top != -1 && stack[top] != '(')
//                 postfix[k++] = pop();
//             pop();
//         }
//         else if (isOperator(c))
//         {
//             while (top != -1 && precedence(stack[top]) >= precedence(c))
//                 postfix[k++] = pop();
//             push(c);
//         }
//     }

//     while (top != -1)
//         postfix[k++] = pop();

//     postfix[k] = '\0';
// }

// int main()
// {
//     char infix[MAX], postfix[MAX];

//     printf("Enter infix expression: ");
//     scanf("%s", infix);

//     infixToPostfix(infix, postfix);

//     printf("Postfix expression: %s\n", postfix);

//     return 0;
// }

// ^ operator included

#include <stdio.h>
#include <stdlib.h>
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
    int i = 0, k = 0;
    char c;

    while ((c = infix[i++]) != '\0')
    {
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

int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
