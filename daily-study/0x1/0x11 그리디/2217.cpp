#include "../bits/stdc++.h"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int s[100010];
    for (int i = 0; i < n; i++) cin >> s[i];
    sort(s, s + n);
    int k = 0;
    for (int i = 0; i < n; i++) k = max(s[i] * (n - i), k);
    cout << k;
    return (0);
}