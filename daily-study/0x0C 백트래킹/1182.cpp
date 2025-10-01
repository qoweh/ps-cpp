#include "../bits/stdc++.h"

using namespace std;

int n, S, cnt;
int arr[20];


void f(int k, int tot) {
    if (k == n) {
        if (tot == S) 
            cnt++;
        return ;
    }
    f(k + 1, tot);
    f(k + 1, tot + arr[k]);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> S;
    for (int i = 0; i < n; i++) cin >> arr[i];
    f(0, 0);
    if (S==0) cnt--;
    cout << cnt;
    return 0;
}