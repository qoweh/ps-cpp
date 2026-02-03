#include "../../bits/stdc++.h"

using namespace std;

int n, M, N, x, y;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}


int f() {
    if (x == M) x = 0;
    if (y == N) y = 0;
    int l = lcm(M, N);
    for (int i = x; i <= l; i += M) {
        if (i == 0) continue; //NOTE -> x=M, y=N일 때 LCM(M,N)대신 0을 반환하는 것을 막기 위해 존재 (이해 x)
        if (i % N == y)
           return i;
    }
    return -1;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> M >> N >> x >> y;
        cout << f() << '\n';
    }

    return (0);
}