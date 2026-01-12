#include "../bits/stdc++.h"
using namespace std;

int arr[10];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int value;
    int answer;

    cin >> value;
    while (value > 0) {    
        arr[value % 10]++;
        value /= 10;
    }
    if (arr[6] - arr[9] >= 2 || arr[9] - arr[6] >= 2)
    {
        int sum_6_9 = arr[6] + arr[9];
        arr[6] = sum_6_9 / 2;
        arr[9] = sum_6_9 / 2 + sum_6_9 % 2;
    }
    answer = arr[0];
    for (int i = 1; i < 10; i++) if (answer < arr[i]) answer = arr[i];
    cout << answer << '\n';
    return 0;
}