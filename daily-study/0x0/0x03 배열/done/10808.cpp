#include <iostream>
using namespace std;

char arr[30];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	for (auto& c : s) {
		arr[c - 'a']++;
	}
	for (int i = 0; i < 'z' - 'a' + 1; i++) {
		cout << (int)arr[i] << ' ';
	}

	return 0;
}