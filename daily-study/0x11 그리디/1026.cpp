#include "../bits/stdc++.h"

using namespace std;

int n, a[55], b[55];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    reverse(b, b +n);

    int res = 0;
    for (int i = 0; i < n; i++) {
        res += a[i] * b[i];
    }
    cout << res;
    return (0);
}