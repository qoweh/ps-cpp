#include <iostream>
using namespace std;

int arr['z' - 'a' + 1];

string f(string a, string b) {
	if (a.size() != b.size())  return "Impossible";
	fill(arr, arr + 'z' - 'a' + 1, 0);
	for (auto& c : a) arr[c - 'a']++;
	for (auto& c : b) {
		if (--arr[c - 'a'] < 0) return "Impossible";
	}
	return "Possible";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	string a, b;

	cin >> n;
	while (n-- > 0) {
		cin >> a >> b;
		cout << f(a, b) << '\n';
	}
	return 0;
}