#include <iostream>
using namespace std;

#define COUNT 'z' - 'a' + 1

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	int arr[COUNT] = {0};
	cin >> s;

	for (char c: s) {
		arr[c - 'a']++;
	}
	for (int i = 0; i < COUNT; i++) {
		cout << arr[i] << ' ';
	}

	return 0;
}