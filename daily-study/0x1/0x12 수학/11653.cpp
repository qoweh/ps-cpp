#include "../../bits/stdc++.h"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int i = 2, n;
    cin >> n;
 
    while (i * i <= n) {
        if (n % i == 0) {
            cout << i << '\n';
            n /= i;
        } else i++;
    }
    if (n != 1) cout << n << '\n';

    return (0);
}