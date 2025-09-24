#include "../bits/stdc++.h"

using namespace std;

int n, cnt;
bool chess[15][15];

bool ispossible(int x, int y) {
    // 상하, 좌우, 기울기 -1 대각선, 기울기 1 대각선
    for (int i = 0; i < n; i++) {
        if (chess[i][y]) return false;
        for (int j = 0; j < n; j++) {
            if (chess[x][j]) return false;
            if (abs(i - x) == abs(j - y) && chess[i][j])
                return false;
        }
    }
    return true;
}

void f(int k) {
    if (k == n) {
        cnt++;
        return ;
    }
    for (int i = 0; i < n; i++) {
        if (ispossible(k, i)) {
            chess[k][i] = true;
            f(k + 1);
            chess[k][i] = false;
        }
    }


}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    fill(&chess[0][0], &chess[0][0] + 15 * 15, false);

    cin >> n;
    f(0);
    cout << cnt;
    return 0;
}