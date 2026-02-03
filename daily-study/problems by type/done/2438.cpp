#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	string s = "";
	cin >> n;
	for (int i = 0; i < n; i++) {
		s += string(i + 1, '*');
		s += '\n';
	}
	cout << s;
	return 0;
}