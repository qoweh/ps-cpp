#include "../../bits/stdc++.h"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, pre = 100000001, cur;
    stack<pair<int, int> > S;
    S.push(make_pair(100000001, 0));
    cin >> n;
    for (int i = 0 ; i < n; i++) {
        cin >> cur;
        while (S.top().first < cur) S.pop();
        cout << S.top().second << ' ';
        S.push(make_pair(cur, i + 1));
        // pre = cur;
    }
    return (0);
}