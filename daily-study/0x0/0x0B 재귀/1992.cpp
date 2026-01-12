#include "../bits/stdc++.h"
using namespace std;

int maps[70][70];

bool is_same_things(int n, int a, int b) {
    int k = maps[a][b];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (k != maps[a + i][b + j])
                return false;
        }
    }
    return true;
}

void f(int n, int a, int  b) {
    if (is_same_things(n, a, b)) {
        cout << maps[a][b];
    } else {
        int half = n / 2;
        cout << '(';
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                f(n / 2, a + i * half, b + j * half);
            }
        }
        cout << ')';
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            maps[i][j] = s[j] - '0';
        }
    }
    f(n, 0, 0);
    return 0;
}