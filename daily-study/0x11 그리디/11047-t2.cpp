#include "../bits/stdc++.h"

using namespace std;

int res, arr[10];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = n - 1; i >= 0; i--) {
        res += k / arr[i];
        k %= arr[i];
    }
    cout << res;
    return (0);
}