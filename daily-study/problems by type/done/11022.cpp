#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, b;
	cin >> n;
	m = n;
	while (n-- > 0) {
		cin >> a >> b;
		cout << "Case #" << m - n << ": " << a << " + " << b << " = " << a + b <<'\n';
	}
	return 0;
}