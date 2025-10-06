#include "../../bits/stdc++.h"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, pre = 0;
    string res;
    stack<int> S;

    cin >> n;
    int x = 1;
    while (n--) {
        int cur;
        cin >> cur;
        if (cur > pre) {
            for (int i = pre; i < cur; i++) {
                res += "+\n";
                S.push(x++);
            }
        } 
        if (cur != S.top()) {
            cout << "NO";
            return 0;
        }
        S.pop();
        res += "-\n";
        pre = max(cur, pre);
    }
    cout << res;
    return (0);
}