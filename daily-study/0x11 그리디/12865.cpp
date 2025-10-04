#include "../bits/stdc++.h"

using namespace std;

int n, k;
int w[105], v[105], D[105][100010];
// D[i][j] : i번째 물건까지, 무게는 jkg까지 고려했을 때의  가치 최대값
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j >= w[i])
                //i번째 물건을 넣는다면, i번째 물건의 가치+dp[i-1][j-i번째 물건의 무게]와 같다. (i번째 물건의 무게만큼 빼줘야 i를 넣음으로써 배낭의 무게가 j이하로 유지할 수 있기 때문이다)
                D[i][j] = max(D[i-1][j], D[i-1][j - w[i]] + v[i]);
            else
                D[i][j] = D[i-1][j];
        }
    }
    cout << D[n][k];
    return (0);
}