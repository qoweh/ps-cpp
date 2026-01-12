#include "../../bits/stdc++.h"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    stack<int> S;
    cin >> n;
    while (n--) {
        cin >> k;
        if (k == 0) S.pop();
        else S.push(k);
    }
    int res = 0;
    while (!S.empty()) {
        res += S.top();
        S.pop();
    }
    cout << res;
    return (0);
}