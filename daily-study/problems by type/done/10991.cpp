#include <iostream>
#include <string>
using namespace std;

string f(int k) {
	string s = "";
	for (int i = 1; i <= k; i++) {
		s += "* ";
	}
	return s;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cout << string(n-i, ' ') + f(i) << '\n';
	}
	return 0;
}