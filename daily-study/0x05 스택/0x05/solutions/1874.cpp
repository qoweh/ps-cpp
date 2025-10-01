// Authored by : haneulkimdev
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/7a18dc82bd4041aaa59c745f06d4ba60
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  stack<int> S;
  int cnt = 1;
  string ans;
  while (n--) { // n(8)번 반복 
    int t;
    cin >> t; // 4 3 6 8 7 5 2 1 하나씩
    while (cnt <= t) {
      S.push(cnt++);
      //NOTE - 이런 식으로 결과를 문자열에 담는 것 좋다.
      ans += "+\n";
    }


    //NOTE - 끝까지 갈 필요없이 return 0; 때려버리는 거 좋다.
    if (S.top() != t) { 
      cout << "NO\n";
      return 0;
    }
    S.pop();


    ans += "-\n";
  }
  cout << ans;
}

/*
현재 처리를 필요로 하는 수는 cnt이다. cnt 이상인 값 t가 주어지면 그 값을 pop할 수 있게 cnt가 t가
될 때 까지 push를 해야 한다(18-21줄). 만약 22번째 줄과 같이 S.top()과 t가 일치하지 않는다면
올바르지 않은 수열이다.
*/
