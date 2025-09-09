#include "../bits/stdc++.h"
using namespace std;

int s[2000001];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, answer = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> x;
    for (int v : arr) {
        if (x > v && s[x - v] == 1) {
            answer++;
            continue;
        }
        s[v] = 1;
    }
    cout << answer << '\n';
    return 0;
}