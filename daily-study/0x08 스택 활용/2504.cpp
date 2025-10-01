#include "../bits/stdc++.h" 

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int p = 0;
    stack<int> I;
    stack<char> C;
    bool inside = true;

    string s;
    cin >> s;
    for (auto i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[') {

            C.push(s[i]);
        }
        else if (s[i] == ')') {
            
            if (s[i-1] == '(') {
                if (inside) {
                    I.push(2);
                    C.pop();
                    inside = false;
                } else {
                    
                }
            } else {
                p = 0;
                break;
            }
        } else if (s[i] == ']') {
            if (s[i-1] == '[') {
                if (inside) {
                    I.push(3);
                    C.pop();
                    inside = false;
                } else {

                }
            } else {
                p = 0;
                break;
            }



        }
    }
    cout << p;
    return 0;
}