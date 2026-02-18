#include "../bits/stdc++.h"
using namespace std;

int vis[501][501];
int input[501][501];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
queue<pair<int, int>> q;

void f(int a, int b);
void bfs(int x, int y, int x_len, int y_len);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y, count = 0, s = 0;
    cin >> x >> y;
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
        cin >> input[i][j];
    
    q.push({0, 0});
    vis[0][0] = 1;

    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            bfs(i, j, x, y);
    
    f(x, y);
    return 0;
}

void bfs(int x, int y, int x_len, int y_len)
{
    while (!q.empty())
    {
        
        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (nx < 0 || nx >= x_len || ny < 0 || ny >= y_len) continue;
            if (vis[nx][ny] == 1 || input[nx][ny] == 0) continue;
            vis[nx][ny] = 1;
    
    
        }
    }
}


void f(int a, int b)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout << input[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}