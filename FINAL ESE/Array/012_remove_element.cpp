#include <iostream>

using namespace std;

// Function to remove all occurrences of 'val' from the array
int removeElement(int nums[], int n, int val) {
    int i = 0;

    // Loop through the array
    for (int j = 0; j < n; j++) {
        // If the current element is not 'val', keep it in the array
        if (nums[j] != val) {
            nums[i] = nums[j];
            i++;  // Move to the next position for non-'val' element
        }
    }

    // Return the new length of the array
    return i;
}

int main() {
    int n, val;

    // Input for size of the array and the value to remove
    cout << "Enter size of the array: ";
    cin >> n;
    int nums[n];

    cout << "Enter elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter value to remove: ";
    cin >> val;

    // Call the removeElement function
    int newLength = removeElement(nums, n, val);

    // Output the new array and the new length
    cout << "Array after removal: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "New length of the array: " << newLength << endl;

    return 0;
}
