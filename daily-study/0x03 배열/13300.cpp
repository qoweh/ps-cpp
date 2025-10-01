#include "../bits/stdc++.h"
using namespace std;

int s[7][2];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, a, b, answer = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        s[b][a]++;
    }
    for (int i = 1; i < 7; i++) {
        if (s[i][0] > 0) answer += (( s[i][0]-1) / k) + 1;
        if (s[i][1] > 0) answer += (( s[i][1]-1) / k) + 1;
    }
    cout << answer << '\n';
    return 0;
}