#include "../../bits/stdc++.h"

using namespace std;

int gcd(int a, int b) {
    // gcd(a, b) = gcd(b, r)
    if (b == 0) return a;
    return gcd(b, a %b);
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << gcd(12, 20) << '\n';

    return (0);
}