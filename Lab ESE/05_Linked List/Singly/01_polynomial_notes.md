### **Explanation of the Polynomial Addition Program**

The given C program represents a polynomial and performs polynomial addition using **singly linked lists**. Each node of the linked list represents a term of the polynomial, where each term has a **coefficient** and a **power**.

---

### **1. Header Files and Structure Definition**

```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int power;
    struct Node* next;
};
```

- **`#include <stdio.h>`**: Provides functions for input and output (e.g., `printf`, `scanf`).
- **`#include <stdlib.h>`**: Provides functions for memory management (`malloc` and `free`).
- **`struct Node`**: Defines a structure representing a term in the polynomial. It has:
  - `coeff`: The coefficient of the polynomial term.
  - `power`: The exponent (power) of the polynomial term.
  - `next`: A pointer to the next node, creating the singly linked list.

---

### **2. Node Creation Function**

```c
struct Node* createNode(int coeff, int power) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}
```

- **Purpose**: Creates a new node for a polynomial term.
- **Explanation**:
  - **`malloc`** allocates memory for a new node.
  - The node's **`coeff`** and **`power`** fields are set to the provided values.
  - The **`next`** pointer is initialized to `NULL`, indicating that this node is the last node (initially).
  - The function returns a pointer to the newly created node.

---

### **3. Insert Term at the End of the Polynomial**

```c
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
```

- **Purpose**: Inserts a new term (node) at the end of the linked list.
- **Explanation**:
  - **`createNode`** is called to create a new node with the given `coeff` and `power`.
  - If the list is empty (`*head == NULL`), set the `head` to point to the new node.
  - If the list is not empty, traverse the list using a `while` loop (`temp->next != NULL`) to reach the last node, then link the last node's `next` to the new node.
  
This function ensures that the polynomial terms are stored in the linked list in the order of insertion (not sorted by power).

---

### **4. Add Two Polynomials**

```c
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
```

- **Purpose**: Adds two polynomials represented by linked lists and stores the result in `result`.
- **Explanation**:
  - The function iterates through both polynomials (`poly1` and `poly2`):
    - If `poly1` has a higher power than `poly2`, the term from `poly1` is added to the result, and `poly1` moves to the next term.
    - If `poly2` has a higher power than `poly1`, the term from `poly2` is added to the result, and `poly2` moves to the next term.
    - If both polynomials have the same power, the coefficients of the terms are added together, and the result is inserted.
  - After the main loop, if any terms remain in `poly1` or `poly2` (i.e., if one list is longer than the other), those terms are added to `result`.

---

### **5. Display Polynomial**

```c
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
```

- **Purpose**: Displays a polynomial represented by a linked list.
- **Explanation**:
  - The function traverses the list and prints each term in the form `coeff*x^power`.
  - If there is a next node (`head->next != NULL`), it prints a `+` sign between terms.
  - The loop continues until all terms are printed.

---

### **6. Main Function**

```c
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
```

- **Purpose**: The main function to interact with the user and manage polynomial input, addition, and output.
- **Explanation**:
  - The program starts by initializing three pointers: `poly1`, `poly2`, and `result` to `NULL`.
  - The program asks the user to input the number of terms and each term’s `coeff` and `power` for both polynomials. These terms are added to `poly1` and `poly2` using `insertEnd`.
  - The `addPolynomials` function is called to add `poly1` and `poly2` and store the result in `result`.
  - Finally, the resultant polynomial is displayed using `displayPolynomial`.

---

### **Time Complexity Analysis**

1. **`insertEnd`**: 
   - Each call to `insertEnd` takes **O(n)** time in the worst case, where `n` is the number of terms already in the list because it traverses the entire list to find the last node. This is due to the linked list being unsorted.
  
2. **`addPolynomials`**:
   - The `addPolynomials` function iterates through both polynomials. If `m` and `n` are the number of terms in `poly1` and `poly2` respectively, the time complexity is **O(m + n)** since it may traverse both lists completely.
  
3. **`displayPolynomial`**:
   - The `displayPolynomial` function traverses the entire result list, which has a maximum of **O(m + n)** terms, where `m` and `n` are the number of terms in `poly1` and `poly2`.

### **Overall Time Complexity**:
- **O(m + n)**, where `m` and `n` are the number of terms in the two polynomials. This is because the program performs operations proportional to the total number of terms in both polynomials (for insertion and addition).

---

### **Space Complexity**:
- **O(m + n)**: The space complexity is determined by the space needed to store the two input polynomials (`poly1`, `poly2`) and the result (`result`), which may each have up to `m + n` terms in the worst case. Thus, the space complexity is linear in terms of the number of terms in both polynomials.

---

### **Example**

If you input:

```
Enter number of terms in first polynomial: 3
Enter terms (coefficient and power):
5 3
4 2
3 0

Enter number of terms in second polynomial: 3
Enter terms (coefficient and power):
3 3
2 2
1 0
```

The two polynomials are:
