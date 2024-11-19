#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int power;
    Node* next;
};

Node* createNode(int coeff, int power) {
    Node* newNode = new Node;
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = nullptr;
    return newNode;
}

void insertEnd(Node*& head, int coeff, int power) {
    Node* newNode = createNode(coeff, power);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void addPolynomials(Node* poly1, Node* poly2, Node*& result) {
    while (poly1 != nullptr && poly2 != nullptr) {
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

    while (poly1 != nullptr) {
        insertEnd(result, poly1->coeff, poly1->power);
        poly1 = poly1->next;
    }

    while (poly2 != nullptr) {
        insertEnd(result, poly2->coeff, poly2->power);
        poly2 = poly2->next;
    }
}

void displayPolynomial(Node* head) {
    while (head != nullptr) {
        cout << head->coeff << "x^" << head->power;
        if (head->next != nullptr) cout << " + ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* poly1 = nullptr;
    Node* poly2 = nullptr;
    Node* result = nullptr;

    int n, coeff, power;
    cout << "Enter number of terms in first polynomial: ";
    cin >> n;
    cout << "Enter terms (coefficient and power):\n";
    for (int i = 0; i < n; i++) {
        cin >> coeff >> power;
        insertEnd(poly1, coeff, power);
    }

    cout << "Enter number of terms in second polynomial: ";
    cin >> n;
    cout << "Enter terms (coefficient and power):\n";
    for (int i = 0; i < n; i++) {
        cin >> coeff >> power;
        insertEnd(poly2, coeff, power);
    }

    addPolynomials(poly1, poly2, result);

    cout << "Resultant polynomial: ";
    displayPolynomial(result);

    return 0;
}
