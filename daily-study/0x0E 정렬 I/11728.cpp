#include "../bits/stdc++.h"

using namespace std;

int n, m;
int arr1[1000005];
int arr2[1000005];
int p[1000005 + 1000005];

void f() {
    int i = 0;
    int k = n + m;
    int idx1 = 0;
    int idx2 = 0;
    while (i < k) {
        if (idx1 >= n) {
            p[i] = arr2[idx2++];
        } else if (idx2 >= m) {
            p[i] = arr1[idx1++];
        } else if (arr1[idx1] >= arr2[idx2]) {
            p[i] = arr2[idx2++];
        } else if (arr1[idx1] < arr2[idx2]) {
            p[i] = arr1[idx1++];
        }
        i++;
    }
}


// using merge sort
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr1[i];
    for (int i = 0; i < m; i++) cin >> arr2[i];

    f();

    for (int i = 0; i < m + n; i++)
        cout << p[i] << ' ';

    return 0;
}