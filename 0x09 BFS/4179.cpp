#include "../bits/stdc++.h"

using namespace std;

int map_F[1000][1000];
int map_J[1000][1000];
string board[1000];
int dx[4] = {0, 1, 0 , -1};
int dy[4] = {1, 0, -1, 0};


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        fill(map_F[i], map_F[i] + m, -1);
        fill(map_J[i], map_J[i] + m, -1);
    }
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    queue<pair<int, int> > Q1;
    queue<pair<int, int> > Q2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'F') {
                Q1.push(make_pair(i, j));
                map_F[i][j] = 0;
            }
            else if (board[i][j] == 'J') {
                Q2.push(make_pair(i, j));
                map_J[i][j] = 0;
            }
        }
    }
    while (!Q1.empty()) {
        auto cur = Q1.front(); Q1.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m 
                || map_F[nx][ny] >= 0
                || board[nx][ny] == '#') continue;
            map_F[nx][ny] = map_F[cur.first][cur.second] + 1;
            Q1.push(make_pair(nx, ny));
        }
    }
        while (!Q2.empty()) {
            auto cur = Q2.front(); Q2.pop();
            for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                cout << map_J[cur.first][cur.second] + 1;
                return 0;
            }
            map_J[nx][ny] = map_J[cur.first][cur.second] + 1;
            Q2.push(make_pair(nx, ny));
        }
    }
    cout << "IMPOSSIBLE";
    
    return 0;
}