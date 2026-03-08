#include <iostream>
using namespace std;

long long dp[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    // 1만 사용하는 경우
    for (int i = 0; i <= 10000; i++)
        dp[i] = 1;

    // 2 사용
    for (int i = 2; i <= 10000; i++)
        dp[i] += dp[i - 2];

    // 3 사용
    for (int i = 3; i <= 10000; i++)
        dp[i] += dp[i - 3];

    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}