#include "../../bits/stdc++.h"

using namespace std;

int s['z' - 'a' + 1];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string S;
    cin >> S;
    for (auto& c: S) {
        s[c - 'a']++;
    }
    for (int i = 0; i < 'z' - 'a' + 1; i++)
        cout << s[i] << ' ';
    return (0);
}