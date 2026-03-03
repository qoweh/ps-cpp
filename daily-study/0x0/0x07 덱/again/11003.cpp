#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

deque<pair<int, int>> d;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, l;
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		while (!d.empty() && d.back().second > k) { // 새로들어온 값(k)보다 d의 back에 큰 값이 있으면 pop해도 됨 -> 최솟값 구할거니까
			d.pop_back();
		}
		d.push_back({i, k});
		while (!d.empty() && d.front().first <= i - l) {
			d.pop_front();
		}
		cout << d.front().second << ' ';
	}
	return 0;
}