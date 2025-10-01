#include "../bits/stdc++.h"
using namespace std;

// Iterative (bottom-up) DP solution for BOJ 12865 (0/1 Knapsack)
// Time: O(n * K), Space: O(K)
// dp[w] = maximum value achievable with total weight exactly w (or up to w when taking max while iterating)
// We iterate weight in descending order to avoid reusing an item multiple times (0/1 constraint).

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, K; // n = number of items, K = capacity
    if (!(cin >> n >> K)) return 0;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; ++i) cin >> w[i] >> v[i];

    vector<int> dp(K + 1, 0);
    for (int i = 0; i < n; ++i) {
        // Traverse backwards to ensure each item is only used once
        for (int curW = K; curW >= w[i]; --curW) {
            dp[curW] = max(dp[curW], dp[curW - w[i]] + v[i]);
        }
    }

    cout << dp[K];
    return 0;
}
