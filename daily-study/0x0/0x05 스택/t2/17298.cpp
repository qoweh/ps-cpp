#include "../../bits/stdc++.h"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, s[1000010];
    stack<int> S;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];

    for (int i = n-1; i>=0; i--) {
        int k = s[i];
        while (!S.empty() && S.top() <= k) S.pop();
        s[i] = S.empty() ? -1 : S.top();
        S.push(k);
    }
    for (int i = 0; i < n; i++) cout << s[i] << ' ';
    return (0);
}