#include "../../bits/stdc++.h"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, v, res = 0;
    int s[105];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    cin >> v;
    for (int i = 0; i < n; i++) if (v == s[i]) res++;
    cout << res;
    return (0);
}