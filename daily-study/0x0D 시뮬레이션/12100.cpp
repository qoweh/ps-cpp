#include "../bits/stdc++.h"

using namespace std;

int n, m, num;
int dx[4] = {1, -1, 0, 0}; // dir : 0, 1, 2, 3과 맞춤 = 남, 북, 동, 서
int dy[4] = {0, 0, 1, -1};
int board1[20][20];
int board2[20][20];

void f(int dir);

void dfs(int cnt) {
    if (cnt == 5) {
        int temp = 0;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                temp = max(temp, board2[x][y]);
            }
        }
        num = max(num, temp);
        return;
    }
    int backup[20][20];
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            backup[x][y] = board2[x][y];
        }
    }
    for (int dir = 0; dir < 4; dir++) {
        f(dir);
        dfs(cnt + 1);
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                board2[x][y] = backup[x][y];
            }
        }
    }
}

void f(int dir) {
    if (dir == 0) { // 남
        for (int y = 0; y < n; y++) {
            vector<int> v;
            for (int x = n - 1; x >= 0; x--) if (board2[x][y]) v.push_back(board2[x][y]);
            vector<int> nv;
            for (int i = 0; i < (int)v.size(); i++) {
                if (i + 1 < (int)v.size() && v[i] == v[i + 1]) { nv.push_back(v[i] * 2); i++; }
                else nv.push_back(v[i]);
            }
            int x = n - 1;
            for (int k = 0; k < (int)nv.size(); k++, x--) board2[x][y] = nv[k];
            for (; x >= 0; x--) board2[x][y] = 0;
        }
    } else if (dir == 1) { // 북
        for (int y = 0; y < n; y++) {
            vector<int> v;
            for (int x = 0; x < n; x++) if (board2[x][y]) v.push_back(board2[x][y]);
            vector<int> nv;
            for (int i = 0; i < (int)v.size(); i++) {
                if (i + 1 < (int)v.size() && v[i] == v[i + 1]) { nv.push_back(v[i] * 2); i++; }
                else nv.push_back(v[i]);
            }
            int x = 0;
            for (int k = 0; k < (int)nv.size(); k++, x++) board2[x][y] = nv[k];
            for (; x < n; x++) board2[x][y] = 0;
        }
    } else if (dir == 2) { // 동
        for (int x = 0; x < n; x++) {
            vector<int> v;
            for (int y = n - 1; y >= 0; y--) if (board2[x][y]) v.push_back(board2[x][y]);
            vector<int> nv;
            for (int i = 0; i < (int)v.size(); i++) {
                if (i + 1 < (int)v.size() && v[i] == v[i + 1]) { nv.push_back(v[i] * 2); i++; }
                else nv.push_back(v[i]);
            }
            int y = n - 1;
            for (int k = 0; k < (int)nv.size(); k++, y--) board2[x][y] = nv[k];
            for (; y >= 0; y--) board2[x][y] = 0;
        }
    } else if (dir == 3) { // 서
        for (int x = 0; x < n; x++) {
            vector<int> v;
            for (int y = 0; y < n; y++) if (board2[x][y]) v.push_back(board2[x][y]);
            vector<int> nv;
            for (int i = 0; i < (int)v.size(); i++) {
                if (i + 1 < (int)v.size() && v[i] == v[i + 1]) { nv.push_back(v[i] * 2); i++; }
                else nv.push_back(v[i]);
            }
            int y = 0;
            for (int k = 0; k < (int)nv.size(); k++, y++) board2[x][y] = nv[k];
            for (; y < n; y++) board2[x][y] = 0;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    num = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board1[i][j];
            num = max(num, board1[i][j]);
        }
    }
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            board2[a][b] = board1[a][b];
        }
    }
    dfs(0);
    cout << num << "\n";
    return 0;
}