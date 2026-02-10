#include <iostream>
#include <algorithm>
using namespace std;

int arr['z' - 'a' + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	fill(arr, arr + 'z' - 'a' + 1, -1);
	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		int idx = s[i] - 'a';
		if (arr[idx] == -1) arr[idx] = i;
	}

	for (int i = 0; i < 'z' - 'a' + 1; i++) {
		cout << arr[i] << ' ';
	}

	return 0;
}