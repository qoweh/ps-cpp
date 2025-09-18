#include "../bits/stdc++.h"

using namespace std;

int nx[4] = {1, 0, -1, 0};
int ny[4] = {0, -1, 0, 1};


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    int M[a][b];
    bool visited[a][b];
    for (auto i = 0; i < a; i++) {
        for (auto j = 0; j < b; j++) {
            int k;
            cin >> k;
            M[i][j] = k; 
        }
    }

    int num = 0, max_area = 0;
    fill(&visited[0][0], &visited[0][0] + (a * b) ,false);
    
    for (auto i = 0; i < a; i++) {
        for (auto j = 0; j < b; j++) {
            queue< pair<int, int> > Q;
            Q.push(make_pair(i, j));
            if (visited[i][j] || M[i][j] == 0) continue;;
            num++;
            visited[i][j] = true;
            int area = 1;
            while (!Q.empty()) {
                pair<int, int> P = Q.front(); Q.pop();
                for (auto p = 0; p < 4; p++) {
                    int ni = P.first + nx[p];
                    int nj = P.second + ny[p];
                    if (ni < 0 || ni >= a || nj < 0 || nj >= b 
                        || visited[ni][nj] == true
                        || M[ni][nj] == 0) continue;
                    visited[ni][nj] = true;
                    area++;
                    Q.push(make_pair(ni, nj));
                }
            }
            max_area = max(max_area, area);
        }
    }
    cout << num << '\n' << (num == 0 ? 0 : max_area);
    return 0;
}