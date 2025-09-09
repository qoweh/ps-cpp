#include "../bits/stdc++.h"
using namespace std;

int arr[10];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int s[3];
    for (int i = 0; i < 3; i++) cin >> s[i];
    long v = (long)(s[0] * s[1] * s[2]);
    while (v > 0) {
        arr[v  % 10]++;
        v /= 10;
    }
    for (int i =0; i < 10; i++)
        cout << arr[i] << '\n';
    return 0;
}