#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	stack<int> s;

	cin >> n;
	while (n-- > 0) {
		string order;
		cin >> order;
		if (order == "push") {
			int t;
			cin >> t;
			s.push(t);
		} else if (order == "pop") {
			if (s.empty()) cout << -1 << '\n';
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		} else if (order == "size") {
			cout << s.size() << '\n';
		} else if (order == "empty") {
			cout << s.empty() << '\n';
		} else if (order == "top") {
			if (s.empty()) cout << -1 << '\n';
			else cout << s.top() << '\n';
		}
	}
	return 0;
}