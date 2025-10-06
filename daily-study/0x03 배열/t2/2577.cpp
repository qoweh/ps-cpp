#include "../../bits/stdc++.h"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> V(3);
    for (int i = 0; i < 3; i++) cin >> V[i];
    int k = V[0] * V[1] * V[2];
    string s = to_string(k);
    int arr[10] = {0};
    for (auto& c: s) {
        arr[c - '0']++;
    }
    for (int i = 0; i < 10; i++) cout << arr[i] << '\n';
    return (0);
}