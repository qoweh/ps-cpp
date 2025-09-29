#include "../bits/stdc++.h"

using namespace std;

int n = 10;
int arr[1000] = {6, -8, 1, 12, 8, 3, 7, -7, -2, 1, 3, 2};

void quick_sort(int st, int en) {
    if (en <= st + 1) return;
    // if (en == st + 1) return;
    int pivot = arr[st];
    int l = st + 1;
    int r = en - 1;

    while (1) {
        while (l <= r && pivot >= arr[l]) l++;
        while (l <= r && pivot < arr[r]) r--;
        if (l > r) break;
        swap(arr[l], arr[r]);
    }
    swap(arr[st], arr[r]);

    quick_sort(st, r);
    quick_sort(r + 1, en);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    quick_sort(0, n);
    for (int i = 0; i < n; i++) { 
        cout << arr[i] << ' ';
    }
    cout << '\n';
    return 0;
}