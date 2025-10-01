#include "../bits/stdc++.h"

using namespace std;

bool isused[5];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // int n = 5;
    // int p = 0;
    // for (int temp = 0; temp < 1 << (2*n); temp++) {
    //     auto k = temp;
    //     for (int i = 0; i < n; i++) {
    //         cout << k % 4;
    //         k /= 4;
    //     }
    //     p++;
    //     cout << '\n';
    // }
    // cout << "\n\n\n";
    // cout << p;
    for (int i = 0; i < 5; i++) {
        cout << (isused[i] == true) << "\n\n";
    }
    return 0;
}