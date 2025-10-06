#include "../../bits/stdc++.h"

using namespace std;

int student[7][2];


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, res = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int m_or_w, grade;
        cin >> m_or_w >> grade;
        student[grade][m_or_w]++;
        if (student[grade][m_or_w] > k) {
            student[grade][m_or_w] = 1;
            res++;
        }
    }
    for (int i = 1; i < 7; i++) {
        if (student[i][0] != 0) {
            res++;
        }
        if (student[i][1] != 0) {
            res++;
        }
    }
    cout << res;
    return (0);
}