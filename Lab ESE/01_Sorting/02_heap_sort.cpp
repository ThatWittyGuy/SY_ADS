#include <iostream>
#include <string>
using namespace std;

struct Student {
    string student_name;
    int student_roll_no;
    int total_marks;
};

// Function to swap two student records
void swap(Student &a, Student &b, int &swapCount) {
    Student temp = a;
    a = b;
    b = temp;
    swapCount++;
}

// Heapify function to maintain the heap property
void heapify(Student arr[], int n, int i, int &swapCount) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check if left child is larger
    if (left < n && arr[left].student_roll_no > arr[largest].student_roll_no)
        largest = left;

    // Check if right child is larger
    if (right < n && arr[right].student_roll_no > arr[largest].student_roll_no)
        largest = right;

    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        swap(arr[i], arr[largest], swapCount);
        heapify(arr, n, largest, swapCount);
    }
}

// Heap sort function
void heapSort(Student arr[], int n, int &swapCount) {
    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, swapCount);

    // One by one extract elements
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i], swapCount);  // Move current root to end
        heapify(arr, i, 0, swapCount);  // Heapify the reduced heap
    }
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    Student arr[n];
    // Input student data
    for (int i = 0; i < n; i++) {
        cout << "Enter name, roll number, and total marks for student " << i + 1 << ":\n";
        cin >> arr[i].student_name >> arr[i].student_roll_no >> arr[i].total_marks;
    }

    int swapCount = 0;
    heapSort(arr, n, swapCount);

    // Output sorted students based on roll number
    cout << "\nSorted student list based on roll number:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i].student_name << " " << arr[i].student_roll_no << " " << arr[i].total_marks << endl;
    }

    cout << "\nNumber of swaps performed: " << swapCount << endl;

    return 0;
}
