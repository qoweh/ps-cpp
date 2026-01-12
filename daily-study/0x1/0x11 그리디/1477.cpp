#include <bits/stdc++.h>

using namespace std;

int n, m, l, s[105], dis[205];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> l;
    for (int i = 1; i <= n; i++) cin >> s[i];
    sort(s + 1, s + 1 + n);
    s[n + 1] = l;
    for (int i = 0 ; i <= n; i++) dis[i] = s[i + 1] - s[i];
    cout << "\n\n";
    sort(dis, dis + n + 1);
    for (int i = 0 ; i <= n; i++) cout << dis[i] << ' ';
    cout << "\n\n";
    int len;
    for (int i = 0; i < m; i++) {
        len = (n+1) + i;
        sort(dis, dis + len);
        int t = dis[len - 1];
        cout << "t:" << t << "\n";
        dis[len - 1] = dis[len] = t / 2;
        if (t % 2 == 1) dis[len]++;
        cout << "dis[len-1]:" << dis[len-1] << ", dis[len]:" << dis[len] << '\n';
    }
    sort(dis, dis + len + 1);
    for (int i = 0 ; i < n + m + 1; i++)
        cout << i << ":" << dis[i] << '\n';
    cout << dis[n + m];
    return (0);
}