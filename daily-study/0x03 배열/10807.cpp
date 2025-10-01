#include "../bits/stdc++.h"
using namespace std;

int s[201];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k; // -100 ~ 100 : 1~100 + -100 ~ -1 + 1 : 201개
        s[k + 100]++;
    }
    cin >> v;
    cout << s[v + 100] << '\n';
    return 0;
}