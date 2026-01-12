#include "../../bits/stdc++.h"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, input[100010] = {}, arr[1000010] = {};
    cin >> n;
    for (int i = 0; i < n; i++) cin >> input[i];

    int x;
    cin >> x;

    int res = 0;
    for (int i = 0; i < n; i++) {
        int k = input[i];
        arr[k]++;
        if (x > k && x != 2*k && arr[x - k] == 1) res++;
    }
    cout << res;
    return (0);
}