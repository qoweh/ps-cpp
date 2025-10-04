#include "../bits/stdc++.h"

using namespace std;

int n, res;
pair<int, int> t[100010];

bool second_fast(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second != p2.second) return p1.second < p2.second;
    return p1.first < p2.first;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        t[i] = make_pair(a, b);
    }
    sort(t, t + n, second_fast);
    
    int pre_end_time = 0;
    for (int i = 0; i < n; i++) {
        if (t[i].first >= pre_end_time) {
            res++;
            pre_end_time = t[i].second;
        }
    }
    cout << res;
    return (0);
}