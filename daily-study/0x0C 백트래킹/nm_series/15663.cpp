#include "../../bits/stdc++.h"

using namespace std;

int n, m;
int arr[8];
int done[8];
bool isused[8];

void f(int k) {
    if (k == m) {
        for (int i = 0; i < k; i++) cout << done[i] << ' ';
        cout << '\n';
        return ;
    }
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (t == arr[i] || isused[i]) continue;
        done[k] = arr[i];
        t = done[k];
        isused[i] = true;
        f(k + 1);
        isused[i] = false;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    f(0);
    return 0;
}