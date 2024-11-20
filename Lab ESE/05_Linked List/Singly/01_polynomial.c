#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int power;
    struct Node* next;
};

struct Node* createNode(int coeff, int power) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int coeff, int power) {
    struct Node* newNode = createNode(coeff, power);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void addPolynomials(struct Node* poly1, struct Node* poly2, struct Node** result) {
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->power > poly2->power) {
            insertEnd(result, poly1->coeff, poly1->power);
            poly1 = poly1->next;
        } else if (poly1->power < poly2->power) {
            insertEnd(result, poly2->coeff, poly2->power);
            poly2 = poly2->next;
        } else {
            int sum = poly1->coeff + poly2->coeff;
            insertEnd(result, sum, poly1->power);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insertEnd(result, poly1->coeff, poly1->power);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertEnd(result, poly2->coeff, poly2->power);
        poly2 = poly2->next;
    }
}

void displayPolynomial(struct Node* head) {
    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->power);
        if (head->next != NULL) {
            printf(" + ");
        }
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;

    int n, coeff, power;
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);
    printf("Enter terms (coefficient and power):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &power);
        insertEnd(&poly1, coeff, power);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);
    printf("Enter terms (coefficient and power):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &power);
        insertEnd(&poly2, coeff, power);
    }

    addPolynomials(poly1, poly2, &result);

    printf("Resultant polynomial: ");
    displayPolynomial(result);

    return 0;
}



// C++ Code
// #include <iostream>
// using namespace std;

// struct Node {
//     int coeff;
//     int power;
//     Node* next;
// };

// Node* createNode(int coeff, int power) {
//     Node* newNode = new Node;
//     newNode->coeff = coeff;
//     newNode->power = power;
//     newNode->next = nullptr;
//     return newNode;
// }

// void insertEnd(Node*& head, int coeff, int power) {
//     Node* newNode = createNode(coeff, power);
//     if (head == nullptr) {
//         head = newNode;
//     } else {
//         Node* temp = head;
//         while (temp->next != nullptr) {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//     }
// }

// void addPolynomials(Node* poly1, Node* poly2, Node*& result) {
//     while (poly1 != nullptr && poly2 != nullptr) {
//         if (poly1->power > poly2->power) {
//             insertEnd(result, poly1->coeff, poly1->power);
//             poly1 = poly1->next;
//         } else if (poly1->power < poly2->power) {
//             insertEnd(result, poly2->coeff, poly2->power);
//             poly2 = poly2->next;
//         } else {
//             int sum = poly1->coeff + poly2->coeff;
//             insertEnd(result, sum, poly1->power);
//             poly1 = poly1->next;
//             poly2 = poly2->next;
//         }
//     }

//     while (poly1 != nullptr) {
//         insertEnd(result, poly1->coeff, poly1->power);
//         poly1 = poly1->next;
//     }

//     while (poly2 != nullptr) {
//         insertEnd(result, poly2->coeff, poly2->power);
//         poly2 = poly2->next;
//     }
// }

// void displayPolynomial(Node* head) {
//     while (head != nullptr) {
//         cout << head->coeff << "x^" << head->power;
//         if (head->next != nullptr) cout << " + ";
//         head = head->next;
//     }
//     cout << endl;
// }

// int main() {
//     Node* poly1 = nullptr;
//     Node* poly2 = nullptr;
//     Node* result = nullptr;

//     int n, coeff, power;
//     cout << "Enter number of terms in first polynomial: ";
//     cin >> n;
//     cout << "Enter terms (coefficient and power):\n";
//     for (int i = 0; i < n; i++) {
//         cin >> coeff >> power;
//         insertEnd(poly1, coeff, power);
//     }

//     cout << "Enter number of terms in second polynomial: ";
//     cin >> n;
//     cout << "Enter terms (coefficient and power):\n";
//     for (int i = 0; i < n; i++) {
//         cin >> coeff >> power;
//         insertEnd(poly2, coeff, power);
//     }

//     addPolynomials(poly1, poly2, result);

//     cout << "Resultant polynomial: ";
//     displayPolynomial(result);

//     return 0;
// }
