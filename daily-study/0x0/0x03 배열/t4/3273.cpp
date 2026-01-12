#include "../../bits/stdc++.h"

using namespace std;

int ans[2000010];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, res = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        ans[x]++;
    }
    cin >> x;

    for (int i = 1; i < x; i++) {
        if (ans[i] == 1 && ans[x-i]== 1) {
            res++;
            ans[i]++;
        }
    }
    cout << res;
    return (0);
}