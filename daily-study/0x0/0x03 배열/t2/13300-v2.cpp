#include "../../bits/stdc++.h"

using namespace std;

int student[7][2];


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, res = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        student[b][a]++;
    }
    for (int i = 1; i <= 6; i++) {
        for (int j = 0; j < 2; j++) {
            res += (student[i][j]) / k;
            if (student[i][j] % k) res++;
        }
    }

    cout << res;
    return (0);
}