#include "../../bits/stdc++.h"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int s['z'-'a'+1] = {};
    string S;

    cin >> S;
    for (auto& c : S) s[c-'a']++;
    cin >> S;
    for (auto& c : S) s[c-'a']--;

    int res = 0;
    for (int i = 0; i < 'z'-'a'+1; i++) {
        if (s[i] != 0) {
            res += abs(s[i]);
        }
    }
    cout << res;
    return (0);
}