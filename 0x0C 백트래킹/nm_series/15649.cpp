#include "../../bits/stdc++.h"

using namespace std;

int n, m;
int arr[8];
bool is_used[9];

void f(int k) {
    if (k == m) {
        for (int i = 0; i < k; i++) cout << arr[i] << ' ';
        cout << '\n';
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (!is_used[i]) {
            arr[k] = i;
            is_used[i] = true;
            f(k + 1);
            is_used[i] = false;
        }   
    }
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    fill(is_used, is_used + 9, false);

    cin >> n >> m;
    f(0);
    return 0;
}