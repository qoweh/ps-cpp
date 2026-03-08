#include <iostream>
#include <queue>
using namespace std;

int logs[1000010];
queue<int> q; // <위치>

// logs를 -1로 표기하여 방문하지 않았음을 명시하는 게 더 좋음

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	q.push(n);
	while (!q.empty()) {
		auto t = q.front(); q.pop();
		if (t == k) {
			cout << logs[t];
			break;
		}
		
		if (t-1 >= 0 && logs[t-1] == 0) {
			logs[t-1] = logs[t] + 1;
			q.push(t-1);
		}
		if (t+1 <= 100000 && logs[t+1] == 0) {
			logs[t+1] = logs[t] + 1;
			q.push(t+1);
		}
		if (2*t <= 100000 && logs[2*t] == 0) {
			logs[2*t] = logs[t] + 1;
			q.push(2*t);
		}
	}
	return 0;
}