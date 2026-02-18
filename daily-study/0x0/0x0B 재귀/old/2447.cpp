#include "../bits/stdc++.h"
using namespace std;

char maps[2200][2200];

void f(int n, int a, int  b) {
    if (n == 1) {
        if (a % 3 == 1 && b % 3 == 1) ; //NOTE - 이 조건은 없어도 됨. 그냥 n == 1일 때는 * 넣어주면 됨.
        else maps[a][b] = '*';
        return ;
    }
    int third = n / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) continue;
            int x = a + i * third;
            int y = b + j * third;
            f(n / 3, x, y);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    fill(&maps[0][0], &maps[0][0] + 2200 * 2200, ' ');
    
    int n;
    cin >> n;
    f(n, 0, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << maps[i][j];
        }
        cout << '\n';
    }
    return 0;
}