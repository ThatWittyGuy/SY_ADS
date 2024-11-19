#include <iostream>
#include <climits>  // For INT_MAX, to track the minimum price

using namespace std;

// Function to calculate the maximum profit
int maxProfit(int prices[], int n) {
    if (n <= 1) return 0;  // No profit if there's only 1 day or less

    int minPrice = INT_MAX;  // Initialize minimum price to the largest possible value
    int maxProfit = 0;  // Initialize maximum profit to 0

    // Loop through each price
    for (int i = 0; i < n; i++) {
        // Update the minimum price if the current price is lower
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }

        // Calculate the profit if selling at current price and update maxProfit
        int profit = prices[i] - minPrice;
        if (profit > maxProfit) {
            maxProfit = profit;
        }
    }

    return maxProfit;  // Return the maximum profit found
}

int main() {
    int n;

    // Input the number of days (size of the array)
    cout << "Enter number of days: ";
    cin >> n;

    int prices[n];

    // Input the stock prices
    cout << "Enter the stock prices for " << n << " days: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    // Call the maxProfit function
    int profit = maxProfit(prices, n);

    // Output the maximum profit
    cout << "Maximum profit that can be made: " << profit << endl;

    return 0;
}
