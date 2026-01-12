#include "../bits/stdc++.h"

using namespace std;

int n;
int D[1000010];
int p[1000010];



int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    D[1] = 0;
    for (int i = 2; i <= n; i++) {
        D[i] = D[i-1] + 1;
        p[i] = i-1;
        if (i % 3 == 0 && D[i] > D[i/3] + 1) {
            D[i] = D[i/3] + 1;
            p[i] = i/3;
        }
        if (i % 2== 0 && D[i] > D[i/2] + 1) {
            D[i] = D[i/2] + 1;
            p[i] = i/2;
        }
    }
    cout << D[n] << '\n';
    while (n != 0) {
        cout << n << ' ';
        n = p[n];
    }
    return (0);
}