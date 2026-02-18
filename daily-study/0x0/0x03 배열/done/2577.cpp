#include <iostream>
#include <string>

using namespace std;

int arr[10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c;
	cin >> a >> b >> c;
	
	// 1,000,000,000 = 10억
	string s = to_string(a * b * c);
	for (auto& c : s) {
		arr[c - '0']++;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}