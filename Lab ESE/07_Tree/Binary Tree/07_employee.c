#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee
{
    int emp_id;
    char name[100];
    float salary;
    struct Employee *left, *right;
};

struct Employee *createEmployee(int emp_id, const char *name, float salary)
{
    struct Employee *newEmployee = (struct Employee *)malloc(sizeof(struct Employee));
    newEmployee->emp_id = emp_id;
    strcpy(newEmployee->name, name);
    newEmployee->salary = salary;
    newEmployee->left = newEmployee->right = NULL;
    return newEmployee;
}

struct Employee *insert(struct Employee *root, struct Employee *newEmployee)
{
    if (root == NULL)
    {
        return newEmployee;
    }
    if (newEmployee->emp_id < root->emp_id)
    {
        root->left = insert(root->left, newEmployee);
    }
    else if (newEmployee->emp_id > root->emp_id)
    {
        root->right = insert(root->right, newEmployee);
    }
    return root;
}

struct Employee *search(struct Employee *root, int emp_id)
{
    if (root == NULL || root->emp_id == emp_id)
    {
        return root;
    }
    if (emp_id < root->emp_id)
    {
        return search(root->left, emp_id);
    }
    return search(root->right, emp_id);
}

void inorderTraversal(struct Employee *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("Emp ID: %d, Name: %s, Salary: %.2f\n", root->emp_id, root->name, root->salary);
    inorderTraversal(root->right);
}

void menu()
{
    printf("\nEmployee Management System\n");
    printf("1. Insert Employee\n");
    printf("2. Search Employee by ID\n");
    printf("3. List Employees in Ascending Order of ID\n");
    printf("4. Exit\n");
}

int main()
{
    struct Employee *root = NULL;
    int choice, emp_id;
    char name[100];
    float salary;

    while (1)
    {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Employee ID: ");
            scanf("%d", &emp_id);
            printf("Enter Employee Name: ");
            getchar();
            fgets(name, 100, stdin);
            name[strcspn(name, "\n")] = '\0';
            printf("Enter Employee Salary: ");
            scanf("%f", &salary);
            root = insert(root, createEmployee(emp_id, name, salary));
            break;
        case 2:
            printf("Enter Employee ID to search: ");
            scanf("%d", &emp_id);
            struct Employee *emp = search(root, emp_id);
            if (emp != NULL)
            {
                printf("Employee Found: ID: %d, Name: %s, Salary: %.2f\n", emp->emp_id, emp->name, emp->salary);
            }
            else
            {
                printf("Employee with ID %d not found.\n", emp_id);
            }
            break;
        case 3:
            printf("Listing all employees in ascending order by ID:\n");
            inorderTraversal(root);
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
