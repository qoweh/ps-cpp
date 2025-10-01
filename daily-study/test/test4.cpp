#include "../bits/stdc++.h"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;
    queue<int> Q;

    cin >> n;
    while (n--) {
        cin >> s;
        if (!s.compare("push")) {
            int k;
            cin >> k;
            Q.push(k);
        } else if (!s.compare("pop")) {
            if (!Q.empty()) {
                cout <<  Q.front() << '\n';
                Q.pop();
            } else {
                cout << -1 << '\n';
            }
        } else if (!s.compare("size")) {
            cout << Q.size() << '\n';
        } else if (!s.compare("empty")) {
            cout << Q.empty() << '\n';
        } else if (!s.compare("front")) {
            cout << (Q.empty() ? -1 : Q.front()) << '\n';
        } else if (!s.compare("back")) {
            cout << (Q.empty() ? -1 : Q.back()) << '\n';
        }
    }

    return 0;
}