#include <iostream>
#include <stack>
#include <string>

using namespace std;


int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string a;
  while(getline(cin, a)){
    stack<char> s;
    
    if(a == ".") break;
    bool valid = true;
    for(auto c : a){
      if(c == '(' || c == '[') s.push(c);
      else if(c == ')'){
        if(s.empty() || s.top() != '('){
          valid = false;
          break;
        }
        s.pop();
      }
      else if(c == ']'){
        if(s.empty() || s.top() != '['){
          valid = false;
          break;
        }
        s.pop();
      }
    }
    if (!s.empty()) valid = false;
    if (valid) cout << "yes\n";
    else cout << "no\n";
  }
}
