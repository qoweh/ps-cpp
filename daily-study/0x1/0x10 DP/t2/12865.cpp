#include "../../bits/stdc++.h"

using namespace std;

int n, k;
int s[110][100010], w[110], v[110];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            // s[i][j] = i번째 물건까지 고려했을 때, 무게 j 이하로 담을 수 있는 최대 가치
            s[i][j] = s[i-1][j];  // i번째 물건을 안 넣는 경우
            if (w[i] <= j) {      // i번째 물건을 넣을 수 있으면
                s[i][j] = max(s[i][j], s[i-1][j-w[i]] + v[i]);
            }
        }
    }
    cout << s[n][k];
    return (0);
}