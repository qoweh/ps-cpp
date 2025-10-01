#include "../bits/stdc++.h"

using namespace std;

int n, k, res = 0;
int w[105], v[105];

void f(int cur_v, int cur_w, int cur_n) {
    if (cur_w > k || cur_n > n) return;
    res = max(res, cur_v);
    for (int i = 0; i < n; i++)
        f(cur_v + v[i], cur_w + w[i], cur_n + 1);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    f(0, 0, 0);
    cout << res;
    return (0);
}