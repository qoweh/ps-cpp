#include "../bits/stdc++.h"

using namespace std;

int f(int N, int r, int c) {
    if (N == 1) {
        return 2 * r + 1 * c;
    }
    return f(N - 1, r % (1 << (N -1)), c % (1 << (N -1))) 
    + (1 << (2*N-2)) * ( 2 * ((1<<(N-1) <= r && r <= (1<<(N)) - 1) ? 1 : 0) + 1 * (((1<<(N-1) <= c && c <= (1<<(N)) - 1) )));
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, r, c;
    cin >> N >> r >> c;
    cout << f(N, r, c);
    return 0;
}