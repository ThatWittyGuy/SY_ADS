#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findElementMoreThanNBy3(const vector<int>& arr) {
    int n = arr.size();
    int threshold = n / 3;

   
    unordered_map<int, int> countMap;

    for (int num : arr) {
        countMap[num]++;
    }


    for (auto& entry : countMap) {
        if (entry.second > threshold) {
            return entry.first; 
    }

    return -1; 
}
}

int main() {
    int n;
    
    // Take input for the size of the array
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    // Take input for the elements of the array
    cout << "Enter elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Find and output the result
    int result = findElementMoreThanNBy3(arr);
    if (result != -1) {
        cout << "Element appearing more than n/3 times: " << result << endl;
    } else {
        cout << "No element appears more than n/3 times." << endl;
    }

    return 0;
}
