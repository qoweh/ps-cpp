#include "../bits/stdc++.h"

using namespace std;

int maps[2200][2200];

int target_count(int n, int a , int b, int target) {
    int c = 0;
    for (int i  = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (target == maps[a + i][b + j])
                c++;
        }
    }
    return c;
}

int f(int n, int a, int  b, int target) {
    if (n == 1)
        return target_count(n , a, b, target);
    int p = 0;
    int third = n / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (target_count(n / 3, a + third * i, b + third * j, target)
                == (n/3) * (n/3))
                p++;
            else
                p += f(n / 3, a + third * i, b + third * j, target);
        }
    }
    return p;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maps[i][j];
        }
    }
    cout << f(n, 0, 0, -1) << '\n';
    cout << f(n, 0, 0, 0) << '\n';
    cout << f(n, 0, 0, 1) << '\n';
    return 0;
}