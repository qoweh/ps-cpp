#include "../../bits/stdc++.h"

using namespace std;

int n, m;
int arr[8];

void f(int k) {
    if (k == m) {
        for (int i = 0; i < k; i++) cout << arr[i] << ' ';
        cout << '\n';
        return ;
    }
    int st = 1;
    if (k != 0) st = arr[k - 1]; // 시작위치 보정
    for (int i = st; i <= n; i++) {
        arr[k] = i;
        f(k + 1);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    f(0);
    return 0;
}