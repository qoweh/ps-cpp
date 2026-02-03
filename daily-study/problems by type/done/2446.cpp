#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= 2 * n - 1; i++) {
		int a = (i <= n) ? i : 2*n - i;
		int b = 2*(n-a) + 1;
		cout << string(a-1, ' ') + string(b, '*') << '\n';
	}

	return 0;
}