#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	while (n > 0) {
		cout << n-- << '\n';
	}
	return 0;
}