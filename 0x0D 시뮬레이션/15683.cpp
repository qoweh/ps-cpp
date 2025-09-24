#include "../bits/stdc++.h"

using namespace std;

int answer;
int maps[8][8];
list<pair<int, int> > cctv;

// bool vis[8][8];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    answer = n * m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maps[i][j];
            if (maps[i][j] != 0 || maps[i][j] != 6)
                cctv.push_back(make_pair(i, j));
        }
    }
    for (int i = 5; i > 0; i--) {
        for (auto iter = cctv.begin(); iter != cctv.end(); iter++) {
            auto p = *iter;
            if (maps[p.first][p.second] != i) continue;
            cctv.remove(p);
            cout << "i: " << i << ", (x,y): (" << p.first << "," << p.second << ")\n";
        }
    }


    return 0;
}