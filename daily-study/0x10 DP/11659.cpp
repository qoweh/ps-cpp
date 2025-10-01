#include "../bits/stdc++.h"

using namespace std;

int D[100010];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int arr[100010];
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) D[i] = D[i-1] + arr[i];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << D[b] - D[a-1] << '\n'; 
    }
    return (0);
}