#include "../bits/stdc++.h"

using namespace std;

list<char> L;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    for (auto& c : s) L.push_back(c);

    int n;
    cin >> n;
    char a, b;
    list<char>::iterator iter = L.end();
    while (n--) {
        cin >> a;
        if (a == 'L' && iter != L.begin()) {
            iter--;
        } else if (a == 'D' && iter != L.end()) {
            iter++;
        } else if (a == 'B' && iter != L.begin()) {
            iter = L.erase(--iter);
        } else if (a == 'P') {
            cin >> b;
            L.insert(iter, b);
        }
    }
    for (auto& c : L) cout << c;
    return (0);
}