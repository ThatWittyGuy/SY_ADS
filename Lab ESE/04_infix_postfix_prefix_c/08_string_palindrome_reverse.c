#include <stdio.h>
#include <string.h>
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

int isPalindrome(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
            return 0;
    }
    return 1;
}

void reverseString(char *str, char *revStr)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        push(str[i]);
    }
    for (int i = 0; i < len; i++)
    {
        revStr[i] = pop();
    }
    revStr[len] = '\0';
}

void concatStrings(char *str1, char *str2, char *result)
{
    int i = 0, j = 0;
    while (str1[i] != '\0')
    {
        result[i] = str1[i];
        i++;
    }
    while (str2[j] != '\0')
    {
        result[i] = str2[j];
        i++;
        j++;
    }
    result[i] = '\0';
}

int compareStrings(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] < str2[i])
            return -1;
        if (str1[i] > str2[i])
            return 1;
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0')
        return 0;
    return (str1[i] == '\0') ? -1 : 1;
}

int main()
{
    char str1[MAX], str2[MAX], result[MAX], revStr[MAX];
    int choice;

    printf("Enter a string: ");
    scanf("%s", str1);

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Palindrome Check\n2. String Reverse\n3. String Concatenation\n4. String Compare\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (isPalindrome(str1))
            {
                printf("The string is a palindrome.\n");
            }
            else
            {
                printf("The string is not a palindrome.\n");
            }
            break;
        case 2:
            reverseString(str1, revStr);
            printf("Reversed string: %s\n", revStr);
            break;
        case 3:
            printf("Enter second string: ");
            scanf("%s", str2);
            concatStrings(str1, str2, result);
            printf("Concatenated string: %s\n", result);
            break;
        case 4:
            printf("Enter second string: ");
            scanf("%s", str2);
            int cmp = compareStrings(str1, str2);
            if (cmp == 0)
                printf("The strings are equal.\n");
            else if (cmp < 0)
                printf("The first string is less than the second string.\n");
            else
                printf("The first string is greater than the second string.\n");
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

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

// int isPalindrome(char *str)
// {
//     int len = strlen(str);
//     for (int i = 0; i < len / 2; i++)
//     {
//         if (str[i] != str[len - i - 1])
//             return 0;
//     }
//     return 1;
// }

// void reverseString(char *str, char *revStr)
// {
//     int len = strlen(str);
//     for (int i = 0; i < len; i++)
//     {
//         push(str[i]);
//     }
//     for (int i = 0; i < len; i++)
//     {
//         revStr[i] = pop();
//     }
//     revStr[len] = '\0';
// }

// void concatStrings(char *str1, char *str2, char *result)
// {
//     int i = 0, j = 0;
//     while (str1[i] != '\0')
//     {
//         result[i] = str1[i];
//         i++;
//     }
//     while (str2[j] != '\0')
//     {
//         result[i] = str2[j];
//         i++;
//         j++;
//     }
//     result[i] = '\0';
// }

// int compareStrings(char *str1, char *str2)
// {
//     return strcmp(str1, str2);
// }

// int main()
// {
//     char str1[MAX], str2[MAX], result[MAX], revStr[MAX];
//     int choice;

//     printf("Enter a string: ");
//     scanf("%s", str1);

//     while (1)
//     {
//         printf("\nMenu:\n");
//         printf("1. Palindrome Check\n2. String Reverse\n3. String Concatenation\n4. String Compare\n5. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//         case 1:
//             if (isPalindrome(str1))
//             {
//                 printf("The string is a palindrome.\n");
//             }
//             else
//             {
//                 printf("The string is not a palindrome.\n");
//             }
//             break;
//         case 2:
//             reverseString(str1, revStr);
//             printf("Reversed string: %s\n", revStr);
//             break;
//         case 3:
//             printf("Enter second string: ");
//             scanf("%s", str2);
//             concatStrings(str1, str2, result);
//             printf("Concatenated string: %s\n", result);
//             break;
//         case 4:
//             printf("Enter second string: ");
//             scanf("%s", str2);
//             int cmp = compareStrings(str1, str2);
//             if (cmp == 0)
//                 printf("The strings are equal.\n");
//             else if (cmp < 0)
//                 printf("The first string is less than the second string.\n");
//             else
//                 printf("The first string is greater than the second string.\n");
//             break;
//         case 5:
//             exit(0);
//         default:
//             printf("Invalid choice.\n");
//         }
//     }
//     return 0;
// }
