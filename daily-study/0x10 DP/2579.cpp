#include "../bits/stdc++.h"

using namespace std;

int arr[301];
int D[301][2];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    if (n == 1) {
        cout << arr[1];
        return 0;
    }
    D[1][1] = arr[1]; //NOTE - 초기값 설정하는 부분 이해 잘 안 됨 
    D[1][2] = 0;
    D[2][1] = arr[2];
    D[2][2] = arr[1] + arr[2];
    for (int i = 3; i <= n; i++) {
        D[i][1] = max(D[i-2][1], D[i-2][2]) + arr[i];
        D[i][2] = D[i-1][1] + arr[i];
    }
    cout << max(D[n][1], D[n][2]);
    return (0);
}