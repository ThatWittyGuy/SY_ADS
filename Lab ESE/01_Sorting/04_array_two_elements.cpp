#include <iostream>
#include <vector>
using namespace std;

void findSwappedPair(vector<int>& A, int n) {
    int first = -1, second = -1;

    for (int i = 0; i < n - 1; i++) {
        if (A[i] > A[i + 1]) {
            first = i;
            break;
        }
    }

    for (int i = n - 1; i > 0; i--) {
        if (A[i] < A[i - 1]) {
            second = i;
            break;
        }
    }

    cout << "Swapped pair: " << A[first] << " and " << A[second] << endl;
    cout << "Positions: " << first << " and " << second << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> A(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    findSwappedPair(A, n);

    return 0;
}
