#include "bits/stdc++.h"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (s.size() > 10) cout << s[0] << s.size() - 2 << s[s.size() - 1];
        else cout << s;
        cout << '\n';
    }
    
    return 0;
}