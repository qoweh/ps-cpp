#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> st;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  long long ans = 0;

  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i]=='(')
      st.push(s[i]);
    else {
      st.pop();
      if (s[i-1] == '(')
        ans+=st.size();
      else ans++;
    }
  }
  cout << ans << "\n";
  return 0;
}
