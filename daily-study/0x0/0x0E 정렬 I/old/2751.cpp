#include "../bits/stdc++.h"

using namespace std;
int arr[1000010];
int temp[1000010];

void merge(int start, int end, int mid) {
    int i = start;
    int j = mid;
    for (int x = start; x < end; x++) {
        if (i == mid) {
            temp[x] = arr[j++];
        } else if (j == end) {
            temp[x] = arr[i++];
        } else if (arr[i] <= arr[j]) {
            temp[x] = arr[i++];
        } else {
            temp[x] = arr[j++];
        }
    }
    for (int x = start; x < end; x++) {
        arr[x] = temp[x];
    }
}

void merge_sort(int start, int end) {
    if (start + 1 == end) return;
    int mid = (start+end)/2;
    merge_sort(start, mid);
    merge_sort(mid, end);
    merge(start, end, mid);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // sort(arr, arr + n);
    merge_sort(0, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }
    return 0;
}