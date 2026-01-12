#include "../bits/stdc++.h"

using namespace std;

long long f1(long a, long b, long c){
    if (b == 1) return (a  % c);
    long long val = f1(a, b / 2, c);
    val = val * val % c;
    if (b % 2 == 0) return val;
    return val * a % c;
}


int f(int a, int b, int c) {
    int var = 1;
    while (b--) {
        var = var * a % c;
    }
    return var;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << (1 << 1) << '\n';
    // cout << (1 << 2) << '\n';
    // cout << (1 << 3);
    // cout << (7 % 4) << '\n';
    // cout << (6 % 4) << '\n';
    // string under_bar = "____";
    // cout << under_bar << "\n";
    // cout << under_bar * 2 << "\n";
    string a = "***************************";
    int i = 0;
    for (char s : a) {
        i++;
    }
    cout << i;
    return 0;
}