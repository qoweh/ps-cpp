#include "../bits/stdc++.h"
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  queue<int> Q;
  int n;

  cin >> n;
  while (n--)
  {
    string init;
    cin >> init;
    if (init == "push")
    {
      int x;
      cin >> x;
      Q.push(x);
    }
    else if (init == "pop")
    {
      if (Q.empty()) cout << -1 << '\n';
      else 
      {
        cout << Q.front() << '\n';
        Q.pop();
      }
    }
    else if (init == "size")
    {
      cout << Q.size() << '\n';
    }
    else if (init == "empty")
    {
      cout << Q.empty() << '\n';
    }
    else if (init == "front")
    {
      if (Q.empty()) cout << -1 << '\n';
      else cout << Q.front() << '\n';
    }
    else if (init == "back")
    {
      if (Q.empty()) cout << -1 << '\n';
      else cout << Q.back() << '\n';
    }   
  }
  return 0;
}
