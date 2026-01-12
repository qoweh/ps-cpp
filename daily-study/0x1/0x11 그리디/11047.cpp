#include "../bits/stdc++.h"

using namespace std;

int res, arr[10];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> arr[i];

    while (k > 0) {
        int i;
        for (i = 0; i < n; i++) {
            if (i == n - 1) break;
            if (arr[i] <= k && k < arr[i + 1]) break;
        }
        res += (k / arr[i]);
        k -= (k / arr[i]) * arr[i];
    }
    cout << res;
    return (0);
}