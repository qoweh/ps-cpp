#include <iostream>
#include <stack>

using namespace std;

stack<int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, i = 1;
	string res;
	res.reserve(20000);
	cin >> n;
	while (n-- > 0) {
		int k;
		cin >> k;
		// stack의 역할 : 1부터 입력값k까지 넣고, pop했을 때 문제가 되는지 안 되는지 시뮬레이션
		while (i <= k) {
			s.push(i++);
			res += "+\n";
		}
		if (!s.empty() && s.top() == k) {
			s.pop();
			res += "-\n";
		}
		else {
			res = "NO";
			break;
		}
	}
	cout << res;
	return 0;
}