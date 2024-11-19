#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string employee_name;
    int emp_no;
    double emp_salary;
};

void swap(Employee &a, Employee &b, int &swapCount) {
    Employee temp = a;
    a = b;
    b = temp;
    swapCount++;
}

int partition(Employee arr[], int low, int high, int &swapCount) {
    int pivot = arr[high].emp_no;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].emp_no < pivot) {
            i++;
            swap(arr[i], arr[j], swapCount);
        }
    }
    swap(arr[i + 1], arr[high], swapCount);
    return i + 1;
}

void quickSort(Employee arr[], int low, int high, int &swapCount) {
    if (low < high) {
        int pi = partition(arr, low, high, swapCount);
        quickSort(arr, low, pi - 1, swapCount);
        quickSort(arr, pi + 1, high, swapCount);
    }
}

int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    Employee arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter name, employee number and salary for employee " << i + 1 << ":\n";
        cin >> arr[i].employee_name >> arr[i].emp_no >> arr[i].emp_salary;
    }

    int swapCount = 0;
    quickSort(arr, 0, n - 1, swapCount);

    cout << "\nSorted employee list based on employee number:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i].employee_name << " " << arr[i].emp_no << " " << arr[i].emp_salary << endl;
    }

    cout << "\nNumber of swaps performed: " << swapCount << endl;

    return 0;
}
