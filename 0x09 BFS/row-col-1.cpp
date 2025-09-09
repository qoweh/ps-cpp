#include "../bits/stdc++.h"
using namespace std;
int board[502][502] =
{{0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; // 1이 파란 칸, 0이 빨간 칸에 대응

void f(int a, int b)
{
    board[a][b] = 1;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  queue<pair<int,int> > Q;
  
  int X = 4, Y = 3;
  f(X, Y);
  f(X-1, Y); // 상
  f(X+1, Y); // 하
  f(X, Y-1); // 좌
  f(X, Y+1); // 우
}