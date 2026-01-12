#include "../../bits/stdc++.h"

using namespace std;

int n, m, k, res = 51;
deque<int> D;

void f(int k, deque<int> d1) {
    int i1 = 0, i2 = 0;
    deque<int> d2 = d1;
    while (1) {
        if (d1.front() == k) {
            d1.pop_front();
            break;
        }
        d1.pop_front();
        i1++;
    }
    while (1) {
        if (d2.back() == k) {
            d2.pop_front();
            break;
        }
        d2.pop_back();
        i2++;
    }
    if (i1 > i2) {
        D = d2;
        res += i2;
    } else {
        D= d1;
        res += i1;
    }
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) D.push_back(i);
    for (int i = 0; i < m; i++) {
        cin >> k;
        f(k, D);
    }
    cout << res;
    return (0);
}