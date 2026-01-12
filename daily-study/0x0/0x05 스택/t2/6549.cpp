#include "../../bits/stdc++.h"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        int n, arr[100010] = {};
        stack<int> S;

        cin >> n; if (n == 0) break;

        int res = 0;
        for (int i = 1 ; i <= n; i++) {
            cin >> arr[i];
            if (arr[i-1] > arr[i] || i == n) { // 감소하는 경우, 구간(@~i-1) 확인해야 함.
                if (i==n) S.push(i);
                int width = 1;
                while (!S.empty()) {
                    res = max(res, arr[S.top()] * width++);
                    // cout << "i: " << i <<  ", res: " << res << "\n";
                    S.pop();
                }
            }
            S.push(i);
        }
        cout << res << '\n';
    }
    return (0);
}