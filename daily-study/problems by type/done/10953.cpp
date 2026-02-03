#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	string s;

	cin >> n;
	while (n-- > 0) {
		k = 0;
		cin >> s;
		for (auto c : s) {
			if (c == ',') continue;
			k += c - '0';
		}
		cout << k <<'\n';
	}
	return 0;
}