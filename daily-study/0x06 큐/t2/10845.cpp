#include "../../bits/stdc++.h"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;
    queue<int> Q;

    cin >> n;
    while (n--){
        cin >> s;
        if (!s.compare("push")) {
            int k;
            cin >> k;
            Q.push(k);
        } else if (!s.compare("pop")) {
            if (Q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << Q.front() << '\n';
                Q.pop();
            }
        } else if (!s.compare("size")) {
            cout << Q.size() << '\n';

        } else if (!s.compare("empty")) {
            cout << Q.empty() << '\n';
        } else if (!s.compare("front")) {
            if (Q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << Q.front() << '\n';
            }
        } else if (!s.compare("back")) {
            if (Q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << Q.back() << '\n';
            }
        }
    }
    return (0);
}