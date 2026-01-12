#include "../bits/stdc++.h"

using namespace std;

int s[1010][3];
int D[1010];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1 ; i <= n; i++) {
        for (int j = 0; j < 3; j++)
            cin >> s[i][j];
    }
    // D[k] = 

    cout << D[n];
    return (0);
}