#include <iostream>

using namespace std;

// Function to check if any value appears at least twice
bool hasDuplicate(int arr[], int n) {
    // Check each element with every other element
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return true;  // If a duplicate is found
            }
        }
    }
    return false;  // No duplicates found
}

int main() {
    int n;

    // Input for the size of the array
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];  // Declare array of size n

    // Input for the elements of the array
    cout << "Enter elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Check for duplicates and output the result
    if (hasDuplicate(arr, n)) {
        cout << "True: There is a duplicate." << endl;
    } else {
        cout << "False: All elements are distinct." << endl;
    }

    return 0;
}
