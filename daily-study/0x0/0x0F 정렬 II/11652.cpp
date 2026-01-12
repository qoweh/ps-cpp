#include "../bits/stdc++.h"

using namespace std;

int n;
long long arr[100010];


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i]; 
    sort(arr, arr + n);

    int cnt = 1;
    long long mxval = arr[0];
    int mxcnt = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i-1]) {
            if (mxcnt < cnt) {
                mxval = arr[i-1];
                mxcnt = cnt;
            }
            cnt = 1;
        } else {
            cnt++;
        }
    }
    if (mxcnt < cnt) mxval = arr[n-1];
    cout << mxval;
    return 0;
}