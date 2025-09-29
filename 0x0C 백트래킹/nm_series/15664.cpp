#include "../../bits/stdc++.h"

using namespace std;

int n, m;
int arr[8];
int done[8];

void f(int k) {
    if (k == m) {
        for (int i = 0; i < k; i++) cout << arr[done[i]] << ' ';
        cout << '\n';
        return ;
    }
    int st = 0;
    if (k != 0) st = done[k - 1] + 1;
    int t = 0;
    for (int i = st; i < n; i++) {
        if (t != arr[i]) {
            done[k] = i;;
            t = arr[i];
            f(k + 1);
        }
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