#include <iostream>
#include <climits>  // For INT_MAX and INT_MIN

using namespace std;

// Function to find the maximum and minimum values in the array
void findMaxMin(int arr[], int n, int result[]) {
    if (n <= 0) {
        result[0] = result[1] = -1;  // Return -1 for both if array is empty
        return;
    }

    int maxNum = INT_MIN;  // Initialize maxNum to the smallest possible value
    int minNum = INT_MAX;  // Initialize minNum to the largest possible value

    // Loop through the array to find max and min
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxNum) {
            maxNum = arr[i];  // Update maxNum if current element is larger
        }
        if (arr[i] < minNum) {
            minNum = arr[i];  // Update minNum if current element is smaller
        }
    }

    // Store the results in the result array
    result[0] = maxNum;  // First element is the maximum
    result[1] = minNum;  // Second element is the minimum
}

int main() {
    int n;

    // Input for the size of the array
    cout << "Enter number of elements in the array: ";
    cin >> n;

    int arr[n];

    // Input for the array elements
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result[2];  // Array to store the max and min values

    // Call the findMaxMin function
    findMaxMin(arr, n, result);

    // Output the maximum and minimum values
    cout << "Maximum value: " << result[0] << endl;
    cout << "Minimum value: " << result[1] << endl;

    return 0;
}
