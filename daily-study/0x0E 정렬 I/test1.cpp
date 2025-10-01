#include "../bits/stdc++.h"

using namespace std;

int arr[8] = {6, -8, 1, 12, 8, 3, 7, -7};

int tidx = 0;

void f(int q) {
    int tmp[8];
    int idx = 0;
    int pivot = arr[q];  // q번째 인덱스를 pivot으로 사용
    for (int i = 0; i < 8; i++) {
        if (i != q && pivot >= arr[i]) tmp[idx++] = arr[i];  // pivot 제외
    }
    tmp[idx++] = pivot;
    for (int i = 0; i < 8; i++) {
        if (i != q && pivot < arr[i]) tmp[idx++] = arr[i];  // pivot 제외
    }
    for (int i = 0; i < 8; i++) {
        arr[i] = tmp[i];
    }
    cout << q << "번째 : ";
    for (int i = 0; i < 8; i++) { 
        cout << arr[i] << ' ';
    }
    cout << '\n';
    cout << '\n';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 8; i++) {
        f(i);
    }

    return 0;
}