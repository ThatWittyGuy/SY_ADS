#include <iostream>
#include <cstdlib>  

using namespace std;

void findSmallestDifferencePair(int A1[], int M, int A2[], int N) {
    int minDiff = 9999;  
    int resultA1 = 0, resultA2 = 0;  

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int diff = abs(A1[i] - A2[j]);
            if (diff < minDiff) {
                minDiff = diff;
                resultA1 = A1[i];
                resultA2 = A2[j];
            }
        }
    }

    cout << "Smallest difference: " << minDiff << endl;
    cout << "Pair with smallest difference: (" << resultA1 << ", " << resultA2 << ")" << endl;
}

int main() {
    int M, N;

    cout << "Enter size of first array: ";
    cin >> M;
    int A1[M];
    cout << "Enter elements of first array: ";
    for (int i = 0; i < M; i++) {
        cin >> A1[i];
    }

    cout << "Enter size of second array: ";
    cin >> N;
    int A2[N];
    cout << "Enter elements of second array: ";
    for (int i = 0; i < N; i++) {
        cin >> A2[i];
    }

    findSmallestDifferencePair(A1, M, A2, N);

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <cstdlib>
// #include <algorithm>

// using namespace std;

// // Function to find the pair with the smallest absolute difference
// pair<int, pair<int, int>> findSmallestDifferencePair(const vector<int>& A1, const vector<int>& A2) {
//     // Sort both arrays to make the search easier
//     vector<int> sortedA1 = A1;
//     vector<int> sortedA2 = A2;
    
//     sort(sortedA1.begin(), sortedA1.end());
//     sort(sortedA2.begin(), sortedA2.end());

//     int i = 0, j = 0;
//     int minDiff = INT_MAX;
//     pair<int, int> resultPair;

//     // Traverse both arrays to find the pair with the smallest difference
//     while (i < sortedA1.size() && j < sortedA2.size()) {
//         int diff = abs(sortedA1[i] - sortedA2[j]);
        
//         // Update minimum difference and result pair
//         if (diff < minDiff) {
//             minDiff = diff;
//             resultPair = {sortedA1[i], sortedA2[j]};
//         }
        
//         // Move the pointer that points to the smaller value
//         if (sortedA1[i] < sortedA2[j]) {
//             i++;
//         } else {
//             j++;
//         }
//     }

//     return {minDiff, resultPair};
// }

// int main() {
//     // Example arrays
//     vector<int> A1 = {1, 5, 9, 13};
//     vector<int> A2 = {2, 6, 8, 12};

//     // Call the function to find the smallest difference pair
//     auto result = findSmallestDifferencePair(A1, A2);

//     // Output the result
//     cout << "Smallest difference: " << result.first << endl;
//     cout << "Pair with smallest difference: (" << result.second.first << ", " << result.second.second << ")" << endl;

//     return 0;
// }
