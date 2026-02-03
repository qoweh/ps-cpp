#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << string(n-i, ' ') << string(i, '*') << '\n';
	}
	for (int i = 1; i <= n-1; i++) {
		cout << string(i, ' ') << string(n-i, '*') << '\n';
	}
	return 0;
}