#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void insertEnd(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

Node* mergeSortedLists(Node* list1, Node* list2) {
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;
    
    if (list1->data < list2->data) {
        list1->next = mergeSortedLists(list1->next, list2);
        if (list1->next != nullptr) {
            list1->next->prev = list1;
        }
        list1->prev = nullptr;
        return list1;
    } else {
        list2->next = mergeSortedLists(list1, list2->next);
        if (list2->next != nullptr) {
            list2->next->prev = list2;
        }
        list2->prev = nullptr;
        return list2;
    }
}

void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;
    int n, data;

    cout << "Enter number of elements for first sorted list: ";
    cin >> n;
    cout << "Enter elements for first sorted list: ";
    for (int i = 0; i < n; i++) {
        cin >> data;
        insertEnd(list1, data);
    }

    cout << "Enter number of elements for second sorted list: ";
    cin >> n;
    cout << "Enter elements for second sorted list: ";
    for (int i = 0; i < n; i++) {
        cin >> data;
        insertEnd(list2, data);
    }

    Node* mergedList = mergeSortedLists(list1, list2);

    cout << "Merged sorted list: ";
    display(mergedList);

    return 0;
}
