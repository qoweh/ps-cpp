#include "../bits/stdc++.h"

using namespace std;

int n, cnt;
bool isused_col[15];     // 열 사용 여부
bool isused_diag1[30];   // / 대각선 (i+j)
bool isused_diag2[30];   // \ 대각선 (i-j+n-1)

void f(int row) {
    if (row == n) {
        cnt++;
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isused_col[col] || isused_diag1[row + col] || isused_diag2[row - col + n - 1])
            continue;
        
        isused_col[col] = true;
        isused_diag1[row + col] = true;
        isused_diag2[row - col + n - 1] = true;
        
        f(row + 1);
        
        isused_col[col] = false;
        isused_diag1[row + col] = false;
        isused_diag2[row - col + n - 1] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    f(0);
    cout << cnt;
    return 0;
}