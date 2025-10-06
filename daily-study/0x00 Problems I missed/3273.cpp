#include "../bits/stdc++.h"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    bool s[2000010] = {false};
    cin >> n;
    for (int i = 0 ; i < n; i++) {
        int k;
        cin >> k;
        s[k] = true;
    }
    cin >> x;
    int res = 0;
    for (int i = 1; i <= (x-1)/2; i++) {
        if (s[i] && s[x-i]) res++;
    }
    cout << res;
    return (0);
}