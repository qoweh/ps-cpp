#include "../bits/stdc++.h"

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    int maps[a][b];
    int nums[a][b];
    fill(&nums[0][0], &nums[0][0] + a * b, -1);
    for (auto i = 0; i < a; i++) {
        string s;
        cin >> s;
        for (auto j =0; j < b; j++) {
            maps[i][j] = s[j] - '0';
        }
    }

    queue<pair<int, int> > Q;
    Q.push(make_pair(0, 0));
    nums[0][0] = 1;
    while (!Q.empty()) {
        pair<int, int> p = Q.front(); Q.pop();
        for (auto i = 0; i < 4; i++) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (nx < 0 || nx >= a || ny < 0 || ny >= b 
                || nums[nx][ny] >= 0
                || maps[nx][ny] == 0) continue;
            nums[nx][ny] = nums[p.first][p.second] + 1;
            Q.push(make_pair(nx, ny));
        }
    }
    cout << nums[a - 1][b - 1];
    return 0;
}