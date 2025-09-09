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
  f(Y, X);
  f(Y - 1, X); // 상
  f(Y + 1, X); // 하
  f(Y, X - 1); // 좌
  f(Y, X + 1); // 우
}