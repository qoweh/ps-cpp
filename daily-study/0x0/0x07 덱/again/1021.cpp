#include <iostream>
#include <deque>

using namespace std;

deque<int> d;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, t, s[55] = {}, res = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) d.push_back(i);
	for (int i = 0; i < m; i++) cin >> s[i];

	for (int i = 0; i < m; i++) {
		if (d.front() != s[i]) {
			int p = find(d.begin(), d.end(), s[i]) - d.begin();
			if (p > d.size()/2) { // 오른쪽으로
				while (d.front() != s[i]) {
					d.push_front(d.back());
					d.pop_back();
					res++;
				}
			} else { // 왼쪽으로
				while (d.front() != s[i]) {
					d.push_back(d.front());
					d.pop_front();
					res++;
				}
			}
		}
		d.pop_front();
	}
	cout << res;
	return 0;
}