#include <iostream>
#include <stack>

using namespace std;

// stack<int> s;
stack<pair<int, int>> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int res[500010];
	cin >> n;

	// stack의 역할 : 특정 위치의 왼쪽에서 볼 수 있는 탑의 후보들을 담는 버퍼
	for (int i = 1; i <= n; i++) {
		int h;
		cin >> h;
		while (!s.empty() && s.top().second < h) {
			s.pop();
		}
		res[i] = (s.empty()) ? 0 : s.top().first; // s에 push하는 것은 index임.
		s.push({i, h});
	}

	for (int i = 1; i <= n; i++) cout << res[i] << ' ';	 
	return 0;
}
