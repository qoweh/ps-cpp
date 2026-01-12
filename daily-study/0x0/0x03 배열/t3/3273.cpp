#include "../../bits/stdc++.h"

using namespace std;

int n, arr[100000], x;
bool s[2000010];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> x;

    int result = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < x && s[x - arr[i]]) result++;
        s[arr[i]] = true;
    }
    cout << result;
    return (0);
}