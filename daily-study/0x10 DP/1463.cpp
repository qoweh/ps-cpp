#include "../bits/stdc++.h"

using namespace std;

int D[1000010];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    D[1] = 0;

    int n;
    cin >> n;

    for (int i = 2; i <=n; i++) {
        D[i] = D[i-1] + 1;
        if (i % 3 == 0) D[i] = min(D[i], D[i/3] + 1);
        if (i % 2 == 0) D[i] = min(D[i], D[i/2] + 1);
    }
    cout << D[n];
    return (0);
}