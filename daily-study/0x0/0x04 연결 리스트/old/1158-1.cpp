#include "../bits/stdc++.h"

using namespace std;

bool s[5005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, c = 0;
    cin >> n >> k;
    
    list<int> L;
    for (int i = 1; i <= n; i++) L.push_back(i);
    list<int>::iterator iter = L.end();
    iter--;
    
    cout << '<';
    while (!L.empty()) {
        int rep = k;
        while (rep--) {
            iter++;
            if (iter == L.end()) iter = L.begin();
        }
        cout << *iter;
        if (L.size() != 1) cout << ", ";
        iter = L.erase(iter);
        iter--;
    }
    cout << '>';
    return (0);
}