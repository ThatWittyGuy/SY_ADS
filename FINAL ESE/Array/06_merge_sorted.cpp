#include <bits/stdc++.h>
using namespace std;

void mergeArrays(vector<int>& arr1, vector<int>& arr2, 
                                    vector<int>& arr3) {
    int n1 = arr1.size();
    int n2 = arr2.size();
    int i = 0, j = 0, k = 0;

    // Traverse arr1 and insert its elements into arr3
    while (i < n1) {
        arr3[k++] = arr1[i++];
    }

    // Traverse arr2 and insert its elements into arr3
    while (j < n2) {
        arr3[k++] = arr2[j++];
    }

    // Sort the entire arr3
    sort(arr3.begin(), arr3.end());
}

// Driver code
int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};
    vector<int> arr3(arr1.size() + arr2.size());

    mergeArrays(arr1, arr2, arr3);

    for (int i = 0; i < arr3.size(); i++)
        cout << arr3[i] << " ";

    return 0;
}
