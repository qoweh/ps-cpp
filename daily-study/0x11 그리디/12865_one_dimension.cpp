#include "../bits/stdc++.h"
using namespace std;

int n, k;
int w[105], v[105], D[105];
// Iterative (bottom-up) DP solution for BOJ 12865 (0/1 Knapsack)
// Time: O(n * K), Space: O(K)
// dp[w] = maximum value achievable with total weight exactly w (or up to w when taking max while iterating)
// We iterate weight in descending order to avoid reusing an item multiple times (0/1 constraint).

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
    for (int i = 1; i <= n; i++) {
        // Traverse backwards to ensure each item is only used once
        for (int cur_w = k; cur_w >= w[i]; --cur_w) {
            D[cur_w] = max(D[cur_w], D[cur_w - w[i]] + v[i]);
        }
    }

    cout << D[k];
    return 0;
}
