#include "../bits/stdc++.h"
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  deque<int> DQ;
  int n;

  cin >> n;
  while (n--)
  {
    string init;
    cin >> init;
    if (init == "push_front")
    {
      int x;
      cin >> x;
      DQ.push_front(x);
    }
    else if (init == "push_back")
    {
      int x;
      cin >> x;
      DQ.push_back(x);
    }
    else if (init == "pop_front")
    {
      if (DQ.empty()) cout << -1 << '\n';
      else 
      {
        cout << DQ.front() << '\n';
        DQ.pop_front();
      }
    }
    else if (init == "pop_back")
    {
      if (DQ.empty()) cout << -1 << '\n';
      else 
      {
        cout << DQ.back() << '\n';
        DQ.pop_back();
      }
    }
    else if (init == "size")
    {
      cout << DQ.size() << '\n';
    }
    else if (init == "empty")
    {
      cout << DQ.empty() << '\n';
    }
    else if (init == "front")
    {
      if (DQ.empty()) cout << -1 << '\n';
      else cout << DQ.front() << '\n';
    }
    else if (init == "back")
    {
      if (DQ.empty()) cout << -1 << '\n';
      else cout << DQ.back() << '\n';
    }   
  }
  return 0;
}