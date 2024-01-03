#include <iostream>
using namespace std;
const int Max=500;

int knapsack(int capacity, const string & weights, const string & values) {
    int n = weights.length();
    int dp[Max][Max];
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
               dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);

            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][capacity];
}

int main() {
    int Capacity = 10;
        string weights = {2, 3, 4, 5};
        string values = {3, 4, 5, 6};

    int maxValue = knapsack(Capacity, weights, values);

    cout << "Maximum Value: " << maxValue << endl;

    return 0;
}
