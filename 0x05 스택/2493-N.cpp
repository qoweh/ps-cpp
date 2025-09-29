#include "../bits/stdc++.h"

using namespace std;

stack<pair<int, int> > S;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    S.push(make_pair(100000001, 0));
    for (int N = 1; N <= n; N++) {
        int cur;
        cin >> cur;
        while (S.top().first < cur)
            S.pop(); // 가장 큰 값 100000001가 있기에 S.pop()에서 에러 안 남.
        cout << S.top().second << ' ';
        S.push(make_pair(cur, N));
    }
    return (0);
}