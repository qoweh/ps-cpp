#include <iostream>
using namespace std;

int lower, upper, num, space;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	while (getline(cin,s)) {
		lower = upper = num = space = 0;
		for (auto& c : s) {
			if (c == ' ') space++;
			else if ('0' <= c && c <= '9') num++;
			else if ('a' <= c && c <= 'z') lower++;
			else if ('A' <= c && c <= 'Z') upper++;
		}
		cout << lower << ' ' << upper << ' ' << num << ' ' << space << '\n';
	}
	return 0;
}