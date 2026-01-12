#include "../bits/stdc++.h"

using namespace std;

int n, k;
int w[105], v[105], D[105][100010];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            D[i][j] = D[i - 1][j];
            if (w[i] <= j) D[i][j] = max(D[i][j], D[i-1][j - w[i]] + v[i]);
        }
    }
    cout << D[n][k];
    return (0);
}