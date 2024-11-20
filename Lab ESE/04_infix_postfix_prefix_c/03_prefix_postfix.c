#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char *c)
{
    if (top < MAX - 1)
        strcpy(stack[++top], c);
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

void prefixToPostfix(char *prefix, char *postfix)
{
    int len = strlen(prefix);
    int k = 0;

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
            sprintf(temp, "%s%s%c", op1, op2, c);
            push(temp);
        }
    }

    strcpy(postfix, pop());
}

int main()
{
    char prefix[MAX], postfix[MAX];

    printf("Enter prefix expression: ");
    scanf("%s", prefix);

    prefixToPostfix(prefix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>

// #define MAX 100

// char stack[MAX][MAX];
// int top = -1;

// void push(char *c)
// {
//     if (top < MAX - 1)
//         strcpy(stack[++top], c);
// }

// char *pop()
// {
//     if (top >= 0)
//         return stack[top--];
//     return NULL;
// }

// int isOperator(char c)
// {
//     return (c == '+' || c == '-' || c == '*' || c == '/');
// }

// void prefixToPostfix(char *prefix, char *postfix)
// {
//     int len = strlen(prefix);
//     int k = 0;

//     for (int i = len - 1; i >= 0; i--)
//     {
//         char c = prefix[i];

//         if (isalnum(c))
//         {
//             char temp[2] = {c, '\0'}; // Single character string
//             push(temp);
//         }
//         else if (isOperator(c))
//         {
//             char *op1 = pop();
//             char *op2 = pop();
//             char temp[MAX];
//             sprintf(temp, "%s%s%c", op1, op2, c); // Concatenate operands and operator
//             push(temp);
//         }
//     }

//     strcpy(postfix, pop()); // The result is now at the top of the stack
// }

// int main()
// {
//     char prefix[MAX], postfix[MAX];

//     printf("Enter prefix expression: ");
//     scanf("%s", prefix);

//     prefixToPostfix(prefix, postfix);

//     printf("Postfix expression: %s\n", postfix);

//     return 0;
// }
