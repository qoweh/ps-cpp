#include "../bits/stdc++.h"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    while (n--) {
        list<char> L;
        list<char>::iterator iter = L.end();
        cin >> s;
        for (auto& c : s) {
            if (c == '-') {
                if (iter != L.begin()) iter = L.erase(--iter);
            } else if (c == '<') {
                if (iter != L.begin()) iter--;
            } else if (c == '>') {
                if (iter != L.end()) iter++;
            } else {
                L.insert(iter, c);
            }
        }
        for (auto& c : L) cout << c;
        cout << '\n';
    }
    return (0);
}