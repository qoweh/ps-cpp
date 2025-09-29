#include "../bits/stdc++.h"

int res[3];
int maps[2200][2200];

using namespace std;

bool is_same_things(int k, int x, int y) {
    int first = maps[x][y];
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (first != maps[x + i][y + j])
                return false;
        }
    }
    return true;
}

void f(int k, int x, int y) {
    if (is_same_things(k, x, y)) {
        res[maps[x][y] + 1]++;
        return ;
    }
    int third = k / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            f(third, x + i * third, y + j * third);
        }
    }
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
    f(n, 0, 0);
    for (int i = 0 ; i< 3; i++)
        cout << res[i] << '\n';
    return (0);
}