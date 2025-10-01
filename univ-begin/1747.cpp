#include "bits/stdc++.h"

using namespace std;

bool is_pelin(int n) {
    string s = to_string(n);
    int len = s.size();
    for (int i = 0; i < len/2; i++)
        if (s[i] != s[len-1-i])
            return false;
    return true;
}

bool is_prime(int n) {
    if (n == 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int next_n(int k) {
    while (1) {
        if (is_pelin(k) && is_prime(k))
            return k;
        k += 2;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if (n <= 2) {
        cout << 2;
        return 0;
    }
    if ((n & 1) == 0) n++;
    cout << next_n(n);
    return 0;
}