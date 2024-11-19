#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};

struct Node *CreateNode(int coeff, int exp)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void InsertNode(struct Node **head, int coeff, int exp)
{
    struct Node *newNode = CreateNode(coeff, exp);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void MultiplyPolynomials(struct Node *p1, struct Node *p2, struct Node **result)
{
    struct Node *temp1 = p1, *temp2 = p2;
    while (temp1 != NULL)
    {
        while (temp2 != NULL)
        {
            int coeff = temp1->coeff * temp2->coeff;
            int exp = temp1->exp + temp2->exp;
            InsertNode(result, coeff, exp);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
        temp2 = p2;
    }
}

void PrintPolynomial(struct Node *head)
{
    while (head != NULL)
    {
        printf("%dx^%d", head->coeff, head->exp);
        if (head->next != NULL)
        {
            printf(" + ");
        }
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct Node *p1 = NULL, *p2 = NULL, *result = NULL;

    InsertNode(&p1, 3, 2);
    InsertNode(&p1, 5, 1);
    InsertNode(&p1, 6, 0);

    InsertNode(&p2, 4, 1);
    InsertNode(&p2, 2, 0);

    MultiplyPolynomials(p1, p2, &result);

    PrintPolynomial(result);

    return 0;
}
