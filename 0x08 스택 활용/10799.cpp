#include "../bits/stdc++.h"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    int result = 0;
    stack<char> S;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            S.push(s[i]);
        }
        else if (s[i] == ')') {
            S.pop();
            if (s[i - 1] == '(') {
                result += S.size();
            } else result++;
        }
    }
    cout << result;
    return 0;
}