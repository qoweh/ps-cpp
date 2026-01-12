#include "../../bits/stdc++.h"

using namespace std;

#define K 'z'-'a'+1


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        int a[K] = {}, b[K] = {};
        string x, y;
        cin >> x >> y;
        for (auto& c : x) a[c-'a']++;
        for (auto& c : y) b[c-'a']++;
        int i;
        for (i = 0; i < K; i++) {
            if (a[i] != b[i]) {
                cout << "Impossible\n";
                break;
            }
        }
        if (i == K) cout << "Possible\n";
    }

    return (0);
}