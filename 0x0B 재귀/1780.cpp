#include "../bits/stdc++.h"
using namespace std;

int maps[2200][2200];
int cnt[3]; // cnt[0]: -1, cnt[1]: 0, cnt[2]: 1

bool is_same_things(int n, int a, int b) {
    int val = maps[a][b];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (maps[a + i][b + j] != val)
                return false;
    return true;
}

void f(int n, int a, int b) {
    if (is_same_things(n, a, b) == true) {
        cnt[maps[a][b] + 1]++; // -1→0, 0→1, 1→2
        return;
    }
    int third = n / 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            f(third, a + i * third, b + j * third);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> maps[i][j];

    f(n, 0, 0);
    cout << cnt[0] << '\n' << cnt[1] << '\n' << cnt[2] << '\n';
    return 0;
}