#include <iostream>
#include <vector>

using namespace std;

// Function to return squares of the array in non-decreasing order
vector<int> sortedSquares(int arr[], int n) {
    vector<int> result(n);  // Vector to store the result

    // Two pointers: one at the beginning, one at the end
    int left = 0, right = n - 1, index = n - 1;

    // Traverse the array from both ends and place the larger square at the current index
    while (left <= right) {
        int leftSquare = arr[left] * arr[left];
        int rightSquare = arr[right] * arr[right];

        if (leftSquare > rightSquare) {
            result[index--] = leftSquare;
            left++;
        } else {
            result[index--] = rightSquare;
            right--;
        }
    }

    return result;
}

int main() {
    int n;

    // Input for the size of the array
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];  // Declare array of size n

    // Input for the elements of the array (sorted)
    cout << "Enter elements of the array (sorted): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Get the sorted squares
    vector<int> result = sortedSquares(arr, n);

    // Output the result
    cout << "Squared elements in non-decreasing order: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
