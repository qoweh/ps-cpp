#include "../../bits/stdc++.h"

using namespace std;

int n, m;
int arr[8];

void f(int k) {
    if (k == m) {
        if (1 /*중복되지 않으면 출력*/) {

        }
        return ;
    }
    for (int i = 0; i < n && i != k; i++) {

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