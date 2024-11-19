#include <iostream>
using namespace std;

// Linear Search Function
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

// Bubble Sort Function
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Binary Search Function (Assumes array is sorted)
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid; // Return index if found
        }
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Return -1 if not found
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, n, target;

    // Input number of elements and the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Menu-driven program
    do {
        cout << "\nMenu:\n";
        cout << "1. Linear Search\n";
        cout << "2. Binary Search\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice != 3) {
            // Input target value for search
            cout << "Enter the number to search: ";
            cin >> target;
        }

        switch (choice) {
            case 1:
                // Linear Search
                int linearResult;
                linearResult = linearSearch(arr, n, target);
                if (linearResult != -1) {
                    cout << "Linear Search: Number " << target << " found at index " << linearResult << endl;
                } else {
                    cout << "Linear Search: Number " << target << " not found\n";
                }
                break;
            case 2:
                // Sort the array using Bubble Sort before Binary Search
                bubbleSort(arr, n);

                // Binary Search
                int binaryResult;
                binaryResult = binarySearch(arr, n, target);
                if (binaryResult != -1) {
                    cout << "Binary Search: Number " << target << " found at index " << binaryResult << endl;
                } else {
                    cout << "Binary Search: Number " << target << " not found\n";
                }
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
