#include <iostream>
#include <string>
using namespace std;

struct Student {
    string student_name;
    int student_roll_no;
    int total_marks;
};

void insertionSort(Student arr[], int n, int &swapCount) {
    for (int i = 1; i < n; ++i) {
        Student key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].student_roll_no > key.student_roll_no) {
            arr[j + 1] = arr[j];
            j--;
            swapCount++;
        }
        arr[j + 1] = key;
    }
}

void merge(Student arr[], int left, int mid, int right, int &swapCount) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    Student L[n1], R[n2];
    
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].student_roll_no <= R[j].student_roll_no) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            swapCount++;  // Swap occurred in merge
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(Student arr[], int left, int right, int &swapCount) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, swapCount);
        mergeSort(arr, mid + 1, right, swapCount);
        merge(arr, left, mid, right, swapCount);
    }
}

void inputStudentData(Student arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> arr[i].student_name;
        cout << "Enter roll number of student " << i + 1 << ": ";
        cin >> arr[i].student_roll_no;
        cout << "Enter total marks of student " << i + 1 << ": ";
        cin >> arr[i].total_marks;
    }
}

void printStudentData(Student arr[], int n) {
    cout << "\nSorted Student List:\n";
    for (int i = 0; i < n; i++) {
        cout << "Name: " << arr[i].student_name
             << ", Roll No: " << arr[i].student_roll_no
             << ", Marks: " << arr[i].total_marks << endl;
    }
}

int main() {
    int n, choice, swapCount;
    
    cout << "Enter the number of students: ";
    cin >> n;

    Student arr[n];
    
    inputStudentData(arr, n);

    do {
        cout << "\nMenu:\n";
        cout << "1. Insertion Sort\n";
        cout << "2. Merge Sort\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        swapCount = 0;

        switch (choice) {
            case 1:
                insertionSort(arr, n, swapCount);
                cout << "Insertion Sort Swap Count: " << swapCount << endl;
                printStudentData(arr, n);
                break;
            case 2:
                mergeSort(arr, 0, n - 1, swapCount);
                cout << "Merge Sort Swap Count: " << swapCount << endl;
                printStudentData(arr, n);
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 3);

    return 0;
}

// #include <iostream>
// #include <string>
// using namespace std;

// struct Student {
//     string student_name;
//     int student_roll_no;
//     int total_marks;
// };

// void insertionSort(Student arr[], int n, int &swapCount) {
//     for (int i = 1; i < n; ++i) {
//         Student key = arr[i];
//         int j = i - 1;
//         while (j >= 0 && arr[j].student_roll_no > key.student_roll_no) {
//             arr[j + 1] = arr[j];
//             j--;
//             swapCount++;
//         }
//         arr[j + 1] = key;
//     }
// }

// void merge(Student arr[], int left, int mid, int right, int &swapCount) {
//     int n1 = mid - left + 1;
//     int n2 = right - mid;
    
//     Student L[n1], R[n2];
    
//     for (int i = 0; i < n1; ++i)
//         L[i] = arr[left + i];
//     for (int i = 0; i < n2; ++i)
//         R[i] = arr[mid + 1 + i];
    
//     int i = 0, j = 0, k = left;
//     while (i < n1 && j < n2) {
//         if (L[i].student_roll_no <= R[j].student_roll_no) {
//             arr[k++] = L[i++];
//         } else {
//             arr[k++] = R[j++];
//             swapCount++;  // Swap occurred in merge
//         }
//     }

//     while (i < n1) arr[k++] = L[i++];
//     while (j < n2) arr[k++] = R[j++];
// }

// void mergeSort(Student arr[], int left, int right, int &swapCount) {
//     if (left < right) {
//         int mid = left + (right - left) / 2;
//         mergeSort(arr, left, mid, swapCount);
//         mergeSort(arr, mid + 1, right, swapCount);
//         merge(arr, left, mid, right, swapCount);
//     }
// }

// void inputStudentData(Student arr[], int n) {
//     for (int i = 0; i < n; i++) {
//         cout << "Enter name of student " << i + 1 << ": ";
//         cin >> arr[i].student_name;
//         cout << "Enter roll number of student " << i + 1 << ": ";
//         cin >> arr[i].student_roll_no;
//         cout << "Enter total marks of student " << i + 1 << ": ";
//         cin >> arr[i].total_marks;
//     }
// }

// void printStudentData(Student arr[], int n) {
//     cout << "\nSorted Student List:\n";
//     for (int i = 0; i < n; i++) {
//         cout << "Name: " << arr[i].student_name
//              << ", Roll No: " << arr[i].student_roll_no
//              << ", Marks: " << arr[i].total_marks << endl;
//     }
// }

// int main() {
//     int n, swapCount;
    
//     cout << "Enter the number of students: ";
//     cin >> n;

//     Student arr[n];
    
//     inputStudentData(arr, n);

//     // Perform Insertion Sort
//     swapCount = 0;
//     insertionSort(arr, n, swapCount);
//     cout << "Insertion Sort Swap Count: " << swapCount << endl;
//     printStudentData(arr, n);

//     // Perform Merge Sort (you can choose this by commenting out the Insertion Sort block above)
//     // swapCount = 0;
//     // mergeSort(arr, 0, n - 1, swapCount);
//     // cout << "Merge Sort Swap Count: " << swapCount << endl;
//     // printStudentData(arr, n);

//     return 0;
// }
