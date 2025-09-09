#include "../bits/stdc++.h"
using namespace std;
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}}; // 1이 파란 칸, 0이 빨간 칸에 대응
bool vis[502][502]; // 해당 칸을 방문했는지 여부를 저장
int n = 7, m = 10; // n = 행의 수, m = 열의 수
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 상하좌우 네 방향을 의미
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> q;
    vis[0][0] = 1;
    q.push({0, 0});
    while (!q.empty())
    {
        pair<int, int> p = q.front(); q.pop();
        cout << "(" << p.X << ", " << p.Y << ") -> ";
        for (int i = 0; i < 4; i++)
        {
            int nx = p.X + dx[i];
            int ny = p.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] == 1 || board[nx][ny] != 1) continue;
            q.push({nx, ny});
            vis[nx][ny] = 1;
        }
    }
    return 0;
}