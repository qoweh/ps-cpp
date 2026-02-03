#include <iostream>
#include <string>
using namespace std;

string f(int a, int b, int c) {
	return string(a, '*') + string(b, ' ') +string(c, '*');
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cout << f(i, 2*(n-i), i) << '\n';
	}
		for (int i = 1; i <= n-1; i++) {
		cout << f(n-i, 2*i, n-i) << '\n';
	}
	return 0;
}