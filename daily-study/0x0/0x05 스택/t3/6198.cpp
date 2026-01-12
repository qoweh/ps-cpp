#include "../../bits/stdc++.h"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, t, result = 0;
    stack<int> S;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        while (!S.empty() && S.top() <= t) {
            S.pop();
        }
        result += S.size();
        S.push(t);
    }
    cout << result;
    return (0);
}