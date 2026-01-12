#include "../../bits/stdc++.h"

using namespace std;

int n, m;
int arr[10];
int idx[10];

void f(int k) {
    if (k == m) {
        for (int i = 0; i < k; i++) cout << arr[idx[i]] << ' ';
        cout << '\n';
        return ;
    }
    
    int same_v = 0;
    for (int i = 0; i < n; i++) {
        if ((k == 0 && same_v != arr[i]) || (same_v != arr[i] && idx[k - 1] <= i)) {
            same_v = arr[i];
            idx[k] = i;
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
    return (0);
}