#include <iostream>
#include <string>
#include <deque>

using namespace std;

deque<int> d;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	while (n-- > 0) {
		string cmd, s, t = "";
		int p, flag = 1, done = 0;
		cin >> cmd >> p >> s;

		for (auto&c : s) {
			if (isdigit(c)) t += c;
			else if (!t.empty()){
				d.push_back(stoi(t));
				t.clear();
			}
		}
		
		for (auto&c : cmd) {
			if (c == 'R') {
				flag = !flag;
			} else if (c == 'D') {
				if (d.empty()) {
					cout << "error\n";
					done = 1;
					break;
				}
				if (flag) {
					d.pop_front();
				} else {
					d.pop_back();
				}
			}
		}
		if (done == 1) continue;
		cout << '[';
		while (!d.empty()) {
			if (flag) {
				cout << d.front();
				d.pop_front();
			} else {
				cout << d.back();
				d.pop_back();
			}
			cout << (d.empty() ? "" : "," );
		}
		cout << "]\n";
	}
	return 0;
}