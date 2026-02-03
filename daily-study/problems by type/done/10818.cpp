#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n;
	vector<int> V(n);
	while (n-- > 0) {
		cin >> V[V.size() - (n + 1)];
	}
	sort(V.begin(), V.end());
	cout << V.front() << ' ' << V.back();
	return 0;
}