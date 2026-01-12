#include "../bits/stdc++.h"

using namespace std;

int n, m, k;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int map1[50][50];
int map2[50][50];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int k_n, k_m;
        cin >> k_n >> k_m;
        // k_n행, k_m열 만큼 스티커 모양 입력받기
        int sticker[10][10];
        for (int a = 0; a < k_n; a++) {
            for (int b = 0; b < k_m; b++) {
                cin >> sticker[a][b];
            }
        }
        // 각 스티커 붙이기
        
    }
    

    return 0;
}