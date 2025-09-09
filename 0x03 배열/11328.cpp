#include "../bits/stdc++.h"
using namespace std;

int s1['z' - 'a' + 1];
int s2['z' - 'a' + 1];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, flag;
    string a, b;
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        flag = 0;
        fill(s1, s1 + 'z' - 'a' + 1, 0);
        fill(s2, s2 + 'z' - 'a' + 1, 0);
        cin >> a >> b;
        for (char c : a) s1[c - 'a']++;
        for (char c : b) s2[c - 'a']++;
        for (int i = 0; i < 'z' - 'a' + 1; i++) 
        {
            if (s1[i] != s2[i])
            {
                cout << "Impossible\n";
                flag = 1;
                break;
            }
        }
        if (!flag)
            cout << "Possible\n";
    }
    return 0;
}
// 0 ~ 9 : 10개
// fill(x, x + 9, 0);