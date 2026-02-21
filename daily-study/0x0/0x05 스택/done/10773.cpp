#include <iostream>
#include <stack>
using namespace std;

stack<int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, res = 0, t;
	cin >> n;
	while (n-- > 0) {
		cin >> t;
		if (t == 0 && !s.empty()) s.pop();
		else s.push(t);
	}
	while (!s.empty()) {
		res += s.top();
		s.pop();
	}
	cout << res;
	return 0;
}