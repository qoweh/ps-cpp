#include "../bits/stdc++.h"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, result = 0;
    string s;
    
    cin >> n;
    while (n--) {
        stack<char> S;
        cin >> s;
        for (auto c : s) {
            if (!S.empty() && S.top() == c) S.pop();
            else S.push(c);        
        }
        if (S.empty()) result++;
    }
    cout << result;

    return 0;
}