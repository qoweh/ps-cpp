#include "../bits/stdc++.h"

using namespace std;

int vis[100001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    fill(vis, vis + 100001, -1);
    queue<pair<int, int> > Q;
    Q.push(make_pair(n, 0));
    vis[n] = 0;

    while (!Q.empty()) {
        pair<int, int> p = Q.front(); Q.pop();
        int x = p.first;
        int time = p.second;
        if (x == k) {
            cout << time;
            return 0;
        }
        int nx[3] = {x + 1, x - 1, 2 * x};
        for (int i = 0; i < 3; i++) {
            if (nx[i] < 0 || nx[i] > 100000) continue;
            if (vis[nx[i]] == -1 || (vis[nx[i]] != -1 && vis[nx[i]] > time + 1)) {
                vis[nx[i]] = time + 1;
                Q.push(make_pair(nx[i], time + 1));
            }
        }
    }
    return 0;
}