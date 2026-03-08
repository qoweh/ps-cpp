#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int board[1001][1001];
bool vst[1001][1001];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue<pair<int, int>> q;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // fill(&vst[0][0], &vst[0][0] + (1001 * 1001), false);
    
    int n, m, res = 0;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { 
            cin >> board[i][j];
            if (board[i][j] == 1) {
                // vst[i][j] = true;   
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (board[nx][ny] == 0) {
                board[nx][ny] = board[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0) flag = true;
            res = max(res, board[i][j]);       
        }
    }
    cout << (flag ? -1 : --res);
    return 0;
}