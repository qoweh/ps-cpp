#include "../bits/stdc++.h"
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, char num){
  dat[unused] = num;
  nxt[unused] = nxt[addr];
  pre[unused] = addr;
  if (nxt[addr] != -1)
    pre[nxt[addr]] = unused;
  nxt[addr] = unused;
  unused++; //?
}

void erase(int addr){
  //addr인 주소의 노드 지우기
  if (nxt[addr] != -1)
    pre[nxt[addr]] = pre[addr];
  nxt[pre[addr]] = nxt[addr];
  dat[addr] = -1;
}

void traverse(){
  int cur = nxt[0];
  while(cur != -1){
    cout << char(dat[cur]);
    cur = nxt[cur];
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(pre, pre+MX, -1);
  fill(nxt, nxt+MX, -1);

  int n, idx = 0;
  char a, b;
  string str;
  cin >> str >> n;
  for (char c : str) insert(idx++, c);
  for (int i = 0; i < n; i++) 
  {
    cin >> a; // L | D | B | P $
    switch (a)
    {
      case 'P':
        cin >> b;
        insert(idx, b);
        idx = nxt[idx];
        break;
      case 'L':
        if (pre[idx] != -1)
          idx = pre[idx];
        break;
      case 'D':
        if (nxt[idx] != -1)
          idx = nxt[idx];
        break;
      case 'B':
        if (pre[idx] != -1)
        {
          erase(idx);
          idx = pre[idx];
        }
        break;
    }
  }
  traverse();
  return 0;
}
