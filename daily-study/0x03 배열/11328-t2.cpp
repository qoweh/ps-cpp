#include "../bits/stdc++.h"
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    while (n--) {
        string first, second;
        int s1['z' - 'a' + 1] = {0};
        int s2['z' - 'a' + 1] = {0};
        
        cin >> first >> second;
        for (auto& c : first) s1[c - 'a']++;
        for (auto& c : second) s2[c - 'a']++;

        bool f = true;
        for (int i = 0; i < 'z' - 'a' + 1; i++) {
            if (s1[i] != s2[i]) {
                f = false;
                break;
            }
        }
        cout << (f ? "Possible\n" : "Impossible\n");
    }
    return 0;
}