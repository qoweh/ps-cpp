#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1; i <= n-1; i++) {
		cout << string(n - i,' ') << '*';
		if (i != 1) cout << string(2*(i-1) - 1, ' ') << '*';
		cout << '\n';
	}
	cout << string(2*n-1, '*') << '\n';
	return 0;
}