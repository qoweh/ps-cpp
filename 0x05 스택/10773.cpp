#include "../bits/stdc++.h"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    stack<int> S;

    cin >> n;
    while (n--) {
        cin >> k;
        if (k != 0)
            S.push(k);
        else if (S.empty() == 0)
            S.pop();
    }
    n = 0;
    while (S.empty() == 0){
        n += S.top();
        S.pop();
    }
    cout << n;
    return 0;
}