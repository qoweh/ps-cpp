#include "bits/stdc++.h"

using namespace std;


//NOTE - DP 배우고 다시 풀어보기








int n, k;
int w[100];
int v[100];
int sum_v;

void f(int count, int cur_w, int cur_v) {
    if (count == n) {
        sum_v = max(sum_v, cur_v);
        return ;
    }
    for (int i = 0; i < n; i++) {
        if (cur_w + w[i] <= k) {
            f(count + 1, cur_w + w[i], cur_v + v[i]);
        } else {
            f(count + 1, cur_w, cur_v);
        }
    }
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    f(0, 0, 0);
    cout << sum_v;
    return 0;
}