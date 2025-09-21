#include "../bits/stdc++.h"

using namespace std;

int maps[1002][1002];
queue<pair<int, int> > Q;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    int m, n;
    cin >> m >> n;
    int status[3] = {0, 0, 0};
    for (auto i = 0; i < n; i++) {
        for (auto j = 0; j < m; j++) {
            cin >> maps[i][j];
            if (maps[i][j] == 1)
                Q.push(make_pair(i, j));
            status[maps[i][j] + 1]++; // -1, 0, 1의 개수 세기
        }
    }
    int count =  status[1]; // 0의 개수
    if (count == 0) {
        cout << 0;
        return 0;
    }

    int result = 0;
    while (!Q.empty()) {
        pair<int, int> P = Q.front(); Q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = P.first + dx[i];
            int ny = P.second + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m
            || maps[nx][ny] != 0) continue;
            maps[nx][ny] = maps[P.first][P.second] + 1;
            count--;
            result = max(result, maps[nx][ny]);
            Q.push(make_pair(nx, ny));
        }
    }    
    cout << (count == 0 ? result - 1 : -1);
    return 0;
}