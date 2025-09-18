#include "../bits/stdc++.h"

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;
    list<char> L;
    list<char>::iterator t;

    cin >> s;
    for (auto c : s) L.push_back(c);

    t = L.end();
    
    cin >> n;
    for (auto i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == 'P') {
            cin >> c; // 띄어쓰기로 인해 한 줄에서 두 번 입력 잘 받는가?
            t = L.insert(t, c);
            t++;
        } else if (c == 'B') {
            if (t != L.begin()){
                t--;
                t = L.erase(t);
            }
        } else if (c == 'L') {
            if (t != L.begin()) t--;
        } else if (c == 'D') {
            if (t != L.end()) t++;
        }
    }
    for (auto c : L) cout << c;

    return 0;
}