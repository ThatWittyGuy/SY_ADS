#include <bits/stdc++.h>
using namespace std;

// Function to count pairs(x, y) where x ^ y > y ^ x
int countPairs(vector<int>& X, vector<int>& Y)
{
    int ans = 0;
    // Iterate over all the possible pairs
    for (int i = 0; i < X.size(); i++)
        for (int j = 0; j < Y.size(); j++)
            // If x ^ y > y ^ x, increment ans
            if (pow(X[i], Y[j]) > pow(Y[j], X[i]))
                ans++;
    return ans;
}

int main()
{
    // Sample Input
    vector<int> X = { 2, 1, 6 };
    vector<int> Y = { 1, 5 };

    cout << countPairs(X, Y);
}
