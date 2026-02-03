#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k = 0;
	string s;
	cin >> n >> s;
	for (auto &c : s) {
		k += c - '0';
	}
	cout << k;
	return 0;
}