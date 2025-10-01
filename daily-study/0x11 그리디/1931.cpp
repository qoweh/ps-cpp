#include "../bits/stdc++.h"

using namespace std;

int n, res;
pair<int, int> t[100010];

void f(int idx, int c) {
    if (t[idx].second > t[n-1].first) {
        res = max(res, c);
        return ;
    }
    for (int i = idx + 1; i < n; i++) {
        if (t[idx].second <= t[i].first)
            f(i, c + 1);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        t[i] = make_pair(a, b);
    }
    sort(t, t + n);
    for (int i = 0; i < n; i++) f(i, 0);
    cout << res + 1;
    return (0);
}