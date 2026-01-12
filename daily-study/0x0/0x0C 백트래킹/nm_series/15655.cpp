#include "../../bits/stdc++.h"

using namespace std;

int n, m;
int input[8];
int arr[8];

void f(int k) {
    if (k == m) {
        for (int i = 0; i < k; i++) cout << arr[i] << ' ';
        cout << '\n';
        return ;
    }
    for (int i = 0; i < n; i++) {
        if (k == 0 || (k != 0 && arr[k - 1] < input[i])) {
            arr[k] = input[i];
            f(k + 1);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> input[i];
    sort(input, input + n);
    f(0);
    return 0;
}