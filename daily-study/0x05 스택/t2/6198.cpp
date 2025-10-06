#include "../../bits/stdc++.h"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> S;
    int n, k;
    long res = 0;
    cin >> n;
    while (n--) {
        cin >> k;
        while(!S.empty() && S.top() < k) S.pop();
        res += (long long) S.size();
        S.push(k);
    }
    cout << res;
    return (0);
}