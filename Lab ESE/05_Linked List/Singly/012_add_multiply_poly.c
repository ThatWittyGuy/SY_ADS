#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node *next;
};

struct Node *CreateNode(int coeff, int exp) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void InsertNode(struct Node **head, int coeff, int exp) {
    struct Node *temp = *head;
    struct Node *prev = NULL;

    while (temp != NULL && temp->exp > exp) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL && temp->exp == exp) {
        temp->coeff += coeff;
    } else {
        struct Node *newNode = CreateNode(coeff, exp);
        if (prev == NULL) {
            *head = newNode;
        } else {
            prev->next = newNode;
        }
        newNode->next = temp;
    }
}

void AddPolynomials(struct Node *p1, struct Node *p2, struct Node **result) {
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            InsertNode(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            InsertNode(result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            int sum = p1->coeff + p2->coeff;
            InsertNode(result, sum, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        InsertNode(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        InsertNode(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }
}

void MultiplyPolynomials(struct Node *p1, struct Node *p2, struct Node **result) {
    struct Node *temp1 = p1, *temp2 = p2;
    while (temp1 != NULL) {
        while (temp2 != NULL) {
            int coeff = temp1->coeff * temp2->coeff;
            int exp = temp1->exp + temp2->exp;
            InsertNode(result, coeff, exp);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
        temp2 = p2;
    }
}

void PrintPolynomial(struct Node *head) {
    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->exp);
        if (head->next != NULL) {
            printf(" + ");
        }
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node *p1 = NULL, *p2 = NULL, *result = NULL;
    int choice, n, coeff, exp;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Polynomials\n");
        printf("2. Multiply Polynomials\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                p1 = p2 = result = NULL;
                printf("Enter number of terms in first polynomial: ");
                scanf("%d", &n);
                printf("Enter terms (coefficient and exponent) for the first polynomial:\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d %d", &coeff, &exp);
                    InsertNode(&p1, coeff, exp);
                }

                printf("Enter number of terms in second polynomial: ");
                scanf("%d", &n);
                printf("Enter terms (coefficient and exponent) for the second polynomial:\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d %d", &coeff, &exp);
                    InsertNode(&p2, coeff, exp);
                }

                AddPolynomials(p1, p2, &result);
                printf("Resultant polynomial after addition: ");
                PrintPolynomial(result);
                break;

            case 2:
                p1 = p2 = result = NULL;
                printf("Enter number of terms in first polynomial: ");
                scanf("%d", &n);
                printf("Enter terms (coefficient and exponent) for the first polynomial:\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d %d", &coeff, &exp);
                    InsertNode(&p1, coeff, exp);
                }

                printf("Enter number of terms in second polynomial: ");
                scanf("%d", &n);
                printf("Enter terms (coefficient and exponent) for the second polynomial:\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d %d", &coeff, &exp);
                    InsertNode(&p2, coeff, exp);
                }

                MultiplyPolynomials(p1, p2, &result);
                printf("Resultant polynomial after multiplication: ");
                PrintPolynomial(result);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
