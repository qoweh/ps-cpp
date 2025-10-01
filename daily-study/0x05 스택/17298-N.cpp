#include "../bits/stdc++.h"

using namespace std;

stack<int> S;
int arr[1000010];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        S.push(k);
    }
    int temp;
    S.push(-1);
    int last = -1;
    for (int N = 1; N <= n; N++) {
        temp = S.top(); S.pop();
        if (S.top() < temp) last = temp;
        if (S.top() > last) arr[n - N] = -1;
        else arr[n - N] = last;
    }
    for (int i = 0; i < n; i++) cout << arr[i] << ' ';
    return (0);
}