#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string a, b, c, d;

	cin >> a >> b >> c >> d;
	cout << stoll(a + b) + stoll(c + d);
	return 0;
}