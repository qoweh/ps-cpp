#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, arr[1'000'001];
queue<pair<int, int>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	fill(arr, arr + n, -1);
	arr[n] = 0;
	q.push({n, 1});
	while (!q.empty()) {
		auto [num, sec] = q.front(); q.pop();
		if (num == 1) break;
		if (num % 3 == 0 && arr[num / 3] == -1) {
			arr[num / 3] = sec;
			q.push({num / 3, sec + 1});
		}
		if (num % 2 == 0 && arr[num / 2] == -1) {
			arr[num / 2] = sec;
			q.push({num / 2, sec + 1});
		}
		if (arr[num - 1] == -1) {
			arr[num - 1] = sec;
			q.push({num - 1, sec + 1});
		}
	}
	cout << arr[1];
	return 0;
}