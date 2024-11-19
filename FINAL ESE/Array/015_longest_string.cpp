#include <iostream>
#include <string>

using namespace std;

string findLongestString(string arr[], int n) {
    if (n == 0) return "";  

    string longest = arr[0];  

    for (int i = 1; i < n; i++) {
        if (arr[i].length() > longest.length()) {
            longest = arr[i];  
        }
    }

    return longest;  
}

int main() {
    int n;

    cout << "Enter number of strings: ";
    cin >> n;

    string arr[n];

    cout << "Enter " << n << " strings: ";
    cin.ignore();  
    for (int i = 0; i < n; i++) {
        getline(cin, arr[i]);  
    }

    string longest = findLongestString(arr, n);

    cout << "The longest string is: " << longest << endl;

    return 0;
}
