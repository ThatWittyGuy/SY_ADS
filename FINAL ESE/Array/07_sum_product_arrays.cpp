#include <iostream>
#include <algorithm>  // for sort
#include <vector>

using namespace std;

// Function to minimize the sum of the product of arrays A and B
int minimizeSumOfProduct(vector<int>& A, vector<int>& B) {
    // Sort array A in ascending order
    sort(A.begin(), A.end());
    
    // Sort array B in descending order
    sort(B.rbegin(), B.rend());
    
    // Calculate the sum of product
    int sum = 0;
    for (size_t i = 0; i < A.size(); ++i) {
        sum += A[i] * B[i];
    }
    
    return sum;
}

int main() {
    int n;
    
    // Take input for the length of arrays
    cout << "Enter the size of arrays: ";
    cin >> n;
    
    vector<int> A(n), B(n);
    
    // Input array A
    cout << "Enter elements of array A: ";
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // Input array B
    cout << "Enter elements of array B: ";
    for (int i = 0; i < n; ++i) {
        cin >> B[i];
    }

    // Call the function to minimize sum of product
    int result = minimizeSumOfProduct(A, B);
    
    // Output the result
    cout << "The minimized sum of the product of A and B is: " << result << endl;
    
    return 0;
}
