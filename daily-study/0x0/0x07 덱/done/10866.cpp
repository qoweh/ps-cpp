#include <iostream>
#include <deque>

using namespace std;

deque<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	while (n-- > 0) {
		string s;
		cin >> s;
		if (s == "push_back") {
			int t;
			cin >> t;
			q.push_back(t);
		} else if (s == "push_front") {
			int t;
			cin >> t;
			q.push_front(t);
		} else if (s == "pop_front") {
			if (q.empty()) {
				cout << -1 << '\n';
			} else {
				cout << q.front() << '\n';
				q.pop_front();
			}
		} else if (s == "pop_back") {
			if (q.empty()) {
				cout << -1 << '\n';
			} else {
				cout << q.back() << '\n';
				q.pop_back();
			}
		} else if (s == "size") {
			cout << q.size() << '\n';
		} else if (s == "empty") {
			cout << q.empty() << '\n';
		} else if (s == "front") {
			cout << (q.empty() ? -1 : q.front()) << '\n';
		} else if (s == "back") {
			cout << (q.empty() ? -1 : q.back()) << '\n';
		}
	}
	return 0;
}