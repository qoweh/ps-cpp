#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, k, arr[100'001];
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> k;
	fill(arr, arr + 100'001, -1);
	arr[n] = 0;
	q.push(n);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		if (now == k) break;
		for (auto x : {now + 1, now - 1, now * 2}) {
			if (x < 0 || x > 100'000) continue;
			if (arr[x] == -1) {
				arr[x] = arr[now] + 1;
				q.push(x);
			}
		}
	}
	cout << arr[k];
	return 0;
}