#include "../bits/stdc++.h"
using namespace std;

int main(void) 
{
  ios::sync_with_stdio(1);
  cin.tie(0);

  stack<int> S;
  int n;
  cin >> n;
  while (n--)
  {
    string init;
    cin >> init;
    if (!init.compare("push"))
    {
      int k;
      cin >> k;
      S.push(k);
    }
    else if (!init.compare("pop"))
    {
      if (S.empty()) cout << -1 << '\n';
      else 
      {
        cout << S.top() << '\n';
        S.pop();
      }
    }
    else if (!init.compare("size"))
    {
        cout << S.size() << '\n';
    }
    else if (!init.compare("empty"))
    {
        if (S.empty()) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
    else if (!init.compare("top"))
    {
        if (S.empty()) cout << -1 << '\n';
        else cout << S.top() << '\n';
    }
  }
  return 0;
}
