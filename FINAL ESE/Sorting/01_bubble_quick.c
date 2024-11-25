#include <stdio.h>
#include <string.h>

struct Student {
    char student_name[50];
    int student_roll_no;
    float total_marks;
};

void swap(struct Student *a, struct Student *b, int *swapCount) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
    (*swapCount)++;
}

void printStudents(struct Student arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Roll No: %d, Total Marks: %.2f\n", arr[i].student_name, arr[i].student_roll_no, arr[i].total_marks);
    }
    printf("\n");
}

void bubbleSort(struct Student arr[], int n, int *swapCount) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j].student_roll_no > arr[j + 1].student_roll_no) {
                swap(&arr[j], &arr[j + 1], swapCount);
            }
        }
    }
}

int partition(struct Student arr[], int low, int high, int *swapCount) {
    int pivot = arr[high].student_roll_no;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].student_roll_no < pivot) {
            i++;
            swap(&arr[i], &arr[j], swapCount);
        }
    }
    swap(&arr[i + 1], &arr[high], swapCount);
    return i + 1;
}

void quickSort(struct Student arr[], int low, int high, int *swapCount) {
    if (low < high) {
        int pi = partition(arr, low, high, swapCount);
        quickSort(arr, low, pi - 1, swapCount);
        quickSort(arr, pi + 1, high, swapCount);
    }
}

int main() {
    int n, swapCount = 0;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student students[n];
    for (int i = 0; i < n; i++) {
        printf("Enter student name, roll_no, total_marks for student %d: ", i + 1);
        scanf("%s %d %f", students[i].student_name, &students[i].student_roll_no, &students[i].total_marks);
    }

    swapCount = 0;
    bubbleSort(students, n, &swapCount);
    printf("\nBubble Sort performed %d swaps.\n", swapCount);
    printStudents(students, n);

    swapCount = 0;
    quickSort(students, 0, n - 1, &swapCount);
    printf("\nQuick Sort performed %d swaps.\n", swapCount);
    printStudents(students, n);

    return 0;
}

// OLD C++ Code
// #include <iostream>
// #include <string>
// using namespace std;

// struct Student {
//     string student_name;
//     int student_roll_no;
//     int total_marks;
// };

// void bubbleSort(Student arr[], int n, int &swapCount) {
//     for (int i = 0; i < n - 1; ++i) {
//         for (int j = 0; j < n - i - 1; ++j) {
//             if (arr[j].student_roll_no > arr[j + 1].student_roll_no) {
//                 swap(arr[j], arr[j + 1]);
//                 swapCount++;
//             }
//         }
//     }
// }

// int partition(Student arr[], int low, int high, int &swapCount) {
//     int pivot = arr[high].student_roll_no;
//     int i = low - 1;
//     for (int j = low; j <= high - 1; ++j) {
//         if (arr[j].student_roll_no < pivot) {
//             i++;
//             swap(arr[i], arr[j]);
//             swapCount++;
//         }
//     }
//     swap(arr[i + 1], arr[high]);
//     swapCount++;
//     return i + 1;
// }

// void quickSort(Student arr[], int low, int high, int &swapCount) {
//     if (low < high) {
//         int pi = partition(arr, low, high, swapCount);
//         quickSort(arr, low, pi - 1, swapCount);
//         quickSort(arr, pi + 1, high, swapCount);
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
//     int n, choice, swapCount;
    
//     cout << "Enter the number of students: ";
//     cin >> n;

//     Student arr[n];
    
//     inputStudentData(arr, n);

//     do {
//         cout << "\nMenu:\n";
//         cout << "1. Bubble Sort\n";
//         cout << "2. Quick Sort\n";
//         cout << "3. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         swapCount = 0;

//         switch (choice) {
//             case 1:
//                 bubbleSort(arr, n, swapCount);
//                 cout << "Bubble Sort Swap Count: " << swapCount << endl;
//                 printStudentData(arr, n);
//                 break;
//             case 2:
//                 quickSort(arr, 0, n - 1, swapCount);
//                 cout << "Quick Sort Swap Count: " << swapCount << endl;
//                 printStudentData(arr, n);
//                 break;
//             case 3:
//                 cout << "Exiting...\n";
//                 break;
//             default:
//                 cout << "Invalid choice, please try again.\n";
//         }
//     } while (choice != 3);

//     return 0;
// }

// #include <iostream>
// #include <string>

// using namespace std;

// struct Student {
//     string student_name;
//     int student_roll_no;
//     int total_marks;
// };

// void bubbleSort(Student arr[], int n, int &swapCount) {
//     for (int i = 0; i < n - 1; ++i) {
//         for (int j = 0; j < n - i - 1; ++j) {
//             if (arr[j].student_roll_no > arr[j + 1].student_roll_no) {
//                 swap(arr[j], arr[j + 1]);
//                 swapCount++;
//             }
//         }
//     }
// }

// int partition(Student arr[], int low, int high, int &swapCount) {
//     int pivot = arr[high].student_roll_no;
//     int i = low - 1;
//     for (int j = low; j <= high - 1; ++j) {
//         if (arr[j].student_roll_no < pivot) {
//             i++;
//             swap(arr[i], arr[j]);
//             swapCount++;
//         }
//     }
//     swap(arr[i + 1], arr[high]);
//     swapCount++;
//     return i + 1;
// }

// void quickSort(Student arr[], int low, int high, int &swapCount) {
//     if (low < high) {
//         int pi = partition(arr, low, high, swapCount);
//         quickSort(arr, low, pi - 1, swapCount);
//         quickSort(arr, pi + 1, high, swapCount);
//     }
// }

// int main() {
//     Student arr[] = {
//         {"Alice", 3, 250},
//         {"Bob", 1, 270},
//         {"Charlie", 2, 230},
//         {"David", 5, 280},
//         {"Eva", 4, 260}
//     };
    
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int swapCount = 0;

//     bubbleSort(arr, n, swapCount);
//     cout << "Bubble Sort Swap Count: " << swapCount << endl;

//     // Resetting array and swap count for quick sort
//     swapCount = 0;
//     Student arr2[] = {
//         {"Alice", 3, 250},
//         {"Bob", 1, 270},
//         {"Charlie", 2, 230},
//         {"David", 5, 280},
//         {"Eva", 4, 260}
//     };

//     quickSort(arr2, 0, n - 1, swapCount);
//     cout << "Quick Sort Swap Count: " << swapCount << endl;

//     return 0;
// }
