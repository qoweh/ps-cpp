#include "../bits/stdc++.h"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    stack<int> P;
    vector<int> V;
    string s;

    cin >> n;
    while (n--) {
        cin >> s;
        if (s == "push") {
            cin >> k;
            P.push(k);
        } else if (s == "pop") {
            if (P.empty()) V.push_back(-1);
            else {
                V.push_back(P.top());
                P.pop();
            }
        } else if (s == "size") {
            V.push_back(P.size());
        } else if (s == "empty") {
            V.push_back(P.empty());
        } else if (s == "top") {
            if (P.empty()) V.push_back(-1);
            else {
                V.push_back(P.top());
            }
        }
    }
    for (auto k : V) cout << k << '\n';
    return 0;
}