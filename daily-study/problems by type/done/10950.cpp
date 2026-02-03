#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a, b;
	cin >> n;
	while (n-- > 0) {
		cin >> a >> b;
		cout << a + b <<'\n';
	}

	return 0;
}