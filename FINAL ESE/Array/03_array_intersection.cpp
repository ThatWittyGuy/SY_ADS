#include <iostream>
#include <vector>

using namespace std;

// Function to find intersection of two sorted arrays
vector<int> findIntersection(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> intersection;
    int i = 0, j = 0;

    // Traverse both arrays to find common elements
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] == arr2[j]) {
            intersection.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j]) {
            i++;
        }
        else {
            j++;
        }
    }

    return intersection;
}

int main() {
    int n1, n2;

    // Input for the first array
    cout << "Enter size of first array: ";
    cin >> n1;
    vector<int> arr1(n1);
    cout << "Enter elements of the first array (sorted): ";
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    // Input for the second array
    cout << "Enter size of second array: ";
    cin >> n2;
    vector<int> arr2(n2);
    cout << "Enter elements of the second array (sorted): ";
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    // Find the intersection
    vector<int> intersection = findIntersection(arr1, arr2);

    // Output the result
    if (!intersection.empty()) {
        cout << "Intersection of the two arrays: ";
        for (int num : intersection) {
            cout << num << " ";
        }
        cout << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    return 0;
}
