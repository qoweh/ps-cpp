#include "../bits/stdc++.h"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    deque<int> D;

    while (n--) {
        string s;
        cin >> s;
        if (s == "push_front") {
            int k;
            cin >> k;
            D.push_front(k);
        } else if (s == "push_back") {
            int k;
            cin >> k;
            D.push_back(k);
        } else if (s == "pop_front") {
            if (D.empty()) {
                cout << -1 << '\n';
            } else {
                cout << D.front() << '\n';
                D.pop_front();
            }
        } else if (s == "pop_back") {
            if (D.empty()) {
                cout << -1 << '\n';
            } else {
                cout << D.back() << '\n';
                D.pop_back();
            }
        } else if (s == "size") {
            cout << D.size() << '\n';
        } else if (s == "empty") {
            cout << D.empty() << '\n';
        } else if (s == "front") {
            cout << (D.empty() ? -1 : D.front()) << '\n';
        } else if (s == "back") {
            cout << (D.empty() ? -1 : D.back()) << '\n';
        }
    }
    return 0;
}