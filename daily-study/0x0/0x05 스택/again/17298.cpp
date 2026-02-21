#include <iostream>
#include <stack>
using namespace std;

stack<int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, t[1000010], k;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> t[i];
	for (int i = n-1; i >= 0; i--) {
		k = t[i];
		while (!s.empty() && s.top() <= k) { 
			// stack은 특정 위치의 오큰수 후보들의 버퍼 역할을 함.
			// 특정 위치의 값(k)가 stack 내의 값들보다 크거나 작으면 stack내의 오큰수 후보들은 의미가 없어서 빼내야 함. ex) 9 5 5 5 7 7 7 에서 -1 7 7 7 -1 -1 -1 [출력되는 7들은 입력 첫번째 7이 될 것임.]
			s.pop();
		}
		t[i] = (s.empty()) ? -1 : s.top();
		s.push(k);
	}
	for (int i = 0; i < n; i++)
		cout << t[i] << ' ';
	return 0;
}