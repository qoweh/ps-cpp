#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> s;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  string str;
  cin >> str;
  int sum = 0; // 누적해서 더해질 값
  int num = 1; // 곱해질 값

  for (int i = 0; i < str.size(); i++){
    if (str[i] == '('){
      num *= 2;
      s.push(str[i]);
    } else if (str[i] == '['){
      num *= 3;
      s.push(str[i]);
    } else if (str[i] == ')'){
      if(s.empty() || s.top() != '('){
        cout << 0;
        return 0;
      }
      if(str[i-1] == '(') sum += num;
      s.pop();
      num /= 2;
    } else if (str[i] == ']'){
      if(s.empty() || s.top() != '['){
        cout << 0;
        return 0;
      }
      if(str[i-1] == '[') sum += num;
      s.pop();
      num /= 3;
    }
  }
  cout << (s.empty() ? sum : 0);
  return 0;
}
