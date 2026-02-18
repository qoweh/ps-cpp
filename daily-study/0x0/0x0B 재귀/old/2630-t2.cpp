#include "../bits/stdc++.h"

using namespace std;

int res[2];
int maps[130][130];

bool is_same_things(int k, int x, int y) {
    int first = maps[x][y];
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (maps[x + i][y + j] != first) {
                return false;
            }
        }
    }
    return true;
}

void f(int k, int x, int y) {
    if (is_same_things(k, x, y)) {
        res[maps[x][y]]++;
        return ;
    }
    int half = k / 2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            f(half, x + half * i, y + half * j);
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
    cout << res[0] << '\n' << res[1];
    return 0;
}