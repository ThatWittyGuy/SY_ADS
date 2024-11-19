#include <iostream>
#include <string>
using namespace std;

struct Student {
    string student_name;
    int student_roll_no;
    int total_marks;
};

int binarySearchIterative(Student arr[], int n, int roll_no) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid].student_roll_no == roll_no) {
            return mid;
        } else if (arr[mid].student_roll_no < roll_no) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int binarySearchRecursive(Student arr[], int left, int right, int roll_no) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (arr[mid].student_roll_no == roll_no) return mid;
    if (arr[mid].student_roll_no < roll_no) return binarySearchRecursive(arr, mid + 1, right, roll_no);
    return binarySearchRecursive(arr, left, mid - 1, roll_no);
}

int main() {
    int n, roll_no, index;

    cout << "Enter the number of students: ";
    cin >> n;

    Student arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> arr[i].student_name;
        cout << "Enter roll number of student " << i + 1 << ": ";
        cin >> arr[i].student_roll_no;
        cout << "Enter total marks of student " << i + 1 << ": ";
        cin >> arr[i].total_marks;
    }

    cout << "Enter the roll number to search: ";
    cin >> roll_no;

    index = binarySearchIterative(arr, n, roll_no);
    if (index != -1) {
        cout << "Found student at index " << index << " (Iterative Search): " << arr[index].student_name << endl;
    } else {
        cout << "Student not found (Iterative Search)" << endl;
    }

    index = binarySearchRecursive(arr, 0, n - 1, roll_no);
    if (index != -1) {
        cout << "Found student at index " << index << " (Recursive Search): " << arr[index].student_name << endl;
    } else {
        cout << "Student not found (Recursive Search)" << endl;
    }

    return 0;
}
