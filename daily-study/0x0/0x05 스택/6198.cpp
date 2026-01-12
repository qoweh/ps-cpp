#include "../bits/stdc++.h"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // stack보단 vector가 낫지 않나?

    int n, result = 0;

    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    stack<int> S;
    

    cout << result;
    return 0;
}