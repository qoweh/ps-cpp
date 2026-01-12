#include "../../bits/stdc++.h"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int arr[10] = {};
    for (auto& c : s) {
        int k = c - '0';
        if (k == 9) arr[6]++;
        else arr[k]++;
    }
    arr[9] = arr[6] / 2;
    arr[6] -= arr[9];
    int t = 0;
    for (int i = 0; i < 9; i++) {
        if (t < arr[i])
            t = arr[i];
    }
    cout << t;
    return (0);
}