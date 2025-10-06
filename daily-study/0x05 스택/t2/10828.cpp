#include "../../bits/stdc++.h"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    stack<int> S;

    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (!s.compare("push")) {
            int p;
            cin >> p;
            S.push(p);
        } else if (!s.compare("pop")) {
            if (S.empty()) {
                cout << -1 << '\n';
            } else {
                cout << S.top() << '\n';
                S.pop();
            }
        } else if (!s.compare("size")) {
            cout << S.size() << '\n';
        } else if (!s.compare("empty")) {
            cout << S.empty() << '\n';
        } else if (!s.compare("top")) {
            if (S.empty()) {
                cout << -1 << '\n';
            } else {
                cout << S.top() << '\n';
            }
        }
    }
    return (0);
}