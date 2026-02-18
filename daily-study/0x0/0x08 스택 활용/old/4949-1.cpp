#include "../bits/stdc++.h"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        string s;
        getline(cin, s);
        if (s == ".") break;
        stack<char> S;

        bool f = false;

        for (auto c : s) {
            if (c == '(' || c == '[') {
                S.push(c);
            } else if (c == ')' || c == ']') {
                if (!S.empty()) {
                    if (S.top() == '(' && c == ')' 
                    || S.top() == '[' && c == ']') S.pop();
                    else S.push(c);
                } else {
                    cout << "no\n";
                    f = true;
                    break;
                }
            }
        }
        if (f) continue;
        cout << (S.empty() ? "yes" : "no") << '\n';
    }

    return 0;
}