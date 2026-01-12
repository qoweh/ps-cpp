#include "../bits/stdc++.h"

using namespace std;

// int s[100010];
int s[2000010];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        s[p]++;
    }
    cin >> x;

    int result = 0;
    for (int i = 1; i <= (x-1) / 2; i++) {
        if (s[i] == 1 && s[x - i] == 1) {
            result++;
        }
    }
    cout << result;
    return 0;
}