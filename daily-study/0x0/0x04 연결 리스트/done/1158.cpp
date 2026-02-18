#include <iostream>
#include <list>

using namespace std;

list<int> L;

void f(int& step) {
	while (!L.empty()) {
		int k = step;
		while (k-- > 0) {
			L.push_back(L.front());
			L.pop_front();
		}
		cout << L.back();
		if (L.size() != 1) cout << ", ";
		L.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) L.push_back(i);

	cout << '<';
	f(k);
	cout << '>';
	return 0;
}