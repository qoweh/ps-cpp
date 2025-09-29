#include "../bits/stdc++.h"

using namespace std;


long long f(int a, int b, int c) {
    if (b == 1) {
        return a % c;
    }
    long long v = f(a, b / 2, c);
    v = v * v % c;
    if (b & 1 == 1) {
        return  v * a % c;
    } else {
        return v % c;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B, C;
    cin >> A >> B >> C;
    cout << f(A, B, C);
    return (0);
}