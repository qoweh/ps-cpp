#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	while (n > 0) {
		cout << string(n--, '*') << '\n';
	}
	return 0;
}