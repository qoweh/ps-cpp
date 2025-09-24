#include "../../bits/stdc++.h"

using namespace std;

int n, m;
int input[8];
int arr[8];
bool isused[8];

void f(int k) {
    if (k == m) {
        for (int i = 0; i < k; i++) cout << input[arr[i]] << ' ';
        cout << '\n';
        return ;
    }
    for (int i = 0; i < n; i++) {
        if (!isused[i]) {
            isused[i] = true;
            arr[k] = i;
            f(k + 1);
            isused[i] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    sort(input, input + n);
    f(0);
    return 0;
}
