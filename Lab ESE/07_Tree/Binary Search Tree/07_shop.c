#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the product item
struct Product
{
    int code;
    char name[100];
    float price;
    int stock;
    char dateReceived[20];
    char expirationDate[20];
    struct Product *left, *right;
};

// Function to create a new product node
struct Product *createProduct(int code, const char *name, float price, int stock, const char *dateReceived, const char *expirationDate)
{
    struct Product *newProduct = (struct Product *)malloc(sizeof(struct Product));
    newProduct->code = code;
    strcpy(newProduct->name, name);
    newProduct->price = price;
    newProduct->stock = stock;
    strcpy(newProduct->dateReceived, dateReceived);
    strcpy(newProduct->expirationDate, expirationDate);
    newProduct->left = newProduct->right = NULL;
    return newProduct;
}

// Function to insert a product into the BST based on product code
struct Product *insert(struct Product *root, struct Product *newProduct)
{
    if (root == NULL)
    {
        return newProduct;
    }
    if (newProduct->code < root->code)
    {
        root->left = insert(root->left, newProduct);
    }
    else if (newProduct->code > root->code)
    {
        root->right = insert(root->right, newProduct);
    }
    return root;
}

// Function to search for a product by its code
struct Product *search(struct Product *root, int code)
{
    if (root == NULL || root->code == code)
    {
        return root;
    }
    if (code < root->code)
    {
        return search(root->left, code);
    }
    return search(root->right, code);
}

// Function to update a product
void updateProduct(struct Product *product)
{
    if (product == NULL)
    {
        printf("Product not found.\n");
        return;
    }

    printf("Enter new name (current: %s): ", product->name);
    getchar(); // To consume the newline left by previous scanf
    fgets(product->name, 100, stdin);
    product->name[strcspn(product->name, "\n")] = '\0'; // Remove the newline character

    printf("Enter new price (current: %.2f): ", product->price);
    scanf("%f", &product->price);

    printf("Enter new stock amount (current: %d): ", product->stock);
    scanf("%d", &product->stock);

    printf("Enter new date received (current: %s): ", product->dateReceived);
    getchar(); // Consume the newline left by previous scanf
    fgets(product->dateReceived, 20, stdin);
    product->dateReceived[strcspn(product->dateReceived, "\n")] = '\0';

    printf("Enter new expiration date (current: %s): ", product->expirationDate);
    fgets(product->expirationDate, 20, stdin);
    product->expirationDate[strcspn(product->expirationDate, "\n")] = '\0';

    printf("Product updated successfully.\n");
}

// Function to print the product details
void printProduct(struct Product *product)
{
    if (product != NULL)
    {
        printf("Code: %d\n", product->code);
        printf("Name: %s\n", product->name);
        printf("Price: %.2f\n", product->price);
        printf("Stock: %d\n", product->stock);
        printf("Date Received: %s\n", product->dateReceived);
        printf("Expiration Date: %s\n\n", product->expirationDate);
    }
}

// Function for lexicographic inorder traversal to list products by name
void inorderTraversal(struct Product *root)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printProduct(root);
    inorderTraversal(root->right);
}

// Display the menu options
void menu()
{
    printf("\nShop Inventory Management\n");
    printf("1. Insert a new product\n");
    printf("2. Find and update a product by its code\n");
    printf("3. List all valid products in lexicographic order\n");
    printf("4. Exit\n");
}

int main()
{
    struct Product *root = NULL;
    int choice, code, stock;
    float price;
    char name[100], dateReceived[20], expirationDate[20];

    while (1)
    {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Insert a new product
            printf("Enter product code: ");
            scanf("%d", &code);
            printf("Enter product name: ");
            getchar(); // To consume the newline character from the previous input
            fgets(name, 100, stdin);
            name[strcspn(name, "\n")] = '\0'; // Remove the newline character
            printf("Enter product price: ");
            scanf("%f", &price);
            printf("Enter stock amount: ");
            scanf("%d", &stock);
            printf("Enter date received (YYYY-MM-DD): ");
            getchar(); // To consume the newline character from the previous input
            fgets(dateReceived, 20, stdin);
            dateReceived[strcspn(dateReceived, "\n")] = '\0'; // Remove newline
            printf("Enter expiration date (YYYY-MM-DD): ");
            fgets(expirationDate, 20, stdin);
            expirationDate[strcspn(expirationDate, "\n")] = '\0'; // Remove newline

            struct Product *newProduct = createProduct(code, name, price, stock, dateReceived, expirationDate);
            root = insert(root, newProduct);
            printf("Product inserted successfully.\n");
            break;

        case 2:
            // Find and update a product by code
            printf("Enter product code to find: ");
            scanf("%d", &code);
            struct Product *product = search(root, code);
            if (product != NULL)
            {
                printf("Product found:\n");
                printProduct(product);
                updateProduct(product);
            }
            else
            {
                printf("Product with code %d not found.\n", code);
            }
            break;

        case 3:
            // List all products in lexicographic order by name
            printf("Listing all valid products in lexicographic order of their names:\n");
            inorderTraversal(root);
            break;

        case 4:
            // Exit the program
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
