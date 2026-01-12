#include "../bits/stdc++.h"

using namespace std;

int n;
int arr[100010];
char result[100010 * 2];
stack<int> S;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    int idx = 0;
    int k = 1;
    int l = 1;
    while (l <= n) {
        S.push(l);
        result[idx++] = '+';
        while (!S.empty() && S.top() == arr[k]) {
            S.pop();
            result[idx++] = '-';
            k++;
        }
        l++;
    }
    if (S.empty()) {
        for (int i = 0; i < idx; i++) cout << result[i] << '\n';
    } else {
        cout << "NO\n";
    }
    return (0);
}