#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return (i+1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// Merge Sort
void merge(int arr[], int left[], int right[], int nLeft, int nRight) {
    int i = 0, j = 0, k = 0;

    while (i < nLeft && j < nRight) {
        if (left[i] < right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < nLeft) {
        arr[k++] = left[i++];
    }

    while (j < nRight) {
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[], int n) {
    if (n < 2) return;

    int mid = n / 2;
    int left[mid], right[n - mid];

    for (int i = 0; i < mid; i++) left[i] = arr[i];
    for (int i = mid; i < n; i++) right[i - mid] = arr[i];

    mergeSort(left, mid);
    mergeSort(right, n - mid);
    merge(arr, left, right, mid, n - mid);
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[minIdx], arr[i]);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    do {
        cout << "\nMenu:\n";
        cout << "1. Bubble Sort\n";
        cout << "2. Quick Sort\n";
        cout << "3. Insertion Sort\n";
        cout << "4. Merge Sort\n";
        cout << "5. Selection Sort\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                bubbleSort(arr, n);
                cout << "Array after Bubble Sort: ";
                printArray(arr, n);
                break;
            case 2:
                quickSort(arr, 0, n-1);
                cout << "Array after Quick Sort: ";
                printArray(arr, n);
                break;
            case 3:
                insertionSort(arr, n);
                cout << "Array after Insertion Sort: ";
                printArray(arr, n);
                break;
            case 4:
                mergeSort(arr, n);
                cout << "Array after Merge Sort: ";
                printArray(arr, n);
                break;
            case 5:
                selectionSort(arr, n);
                cout << "Array after Selection Sort: ";
                printArray(arr, n);
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
