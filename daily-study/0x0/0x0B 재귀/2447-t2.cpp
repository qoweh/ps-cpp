#include "../bits/stdc++.h"
using namespace std;

int n;
char maps[2200][2200] = {' '};

void f(int m, int x, int y) {
    if (m == 1) {
        /* if (x % 3 == 1 && y % 3 == 1); // 여기는 필요없는 부분임.
        else */ maps[x][y] = '*';
        return ;
    }
    int third = m / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) continue;
            f(third, x + third * i, y + third * j);
        }
    }
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    fill(&maps[0][0], &maps[0][0] + 2200 * 2200, ' ');
    
    cin >> n;
    f(n, 0, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << maps[i][j];
        }
        cout << '\n';
    }
    return 0;
}