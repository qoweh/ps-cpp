#include <iostream>
#include <cctype>

using namespace std;

#define COUNT ('z' - 'a' + 1)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	getline(cin, s);
	for (auto& c : s) {
		if (islower(c)) {
			c = 'a' + (c - 'a' + 13) % COUNT;
		} else if (isupper(c)) {
			c = 'A' + (c - 'A' + 13) % COUNT;
		}
    	cout << c;
	}

	return 0;
}