#include <iostream>
#include <list>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	list<char> L;
	string s;
	cin >> s;
	
	for (auto&c : s) L.push_back(c);

	int n;
	char t;
	list<char>::iterator iter = L.end();
	cin >> n;

	while (n--) {
		cin >> t;
		if (t == 'L') {
			if (iter != L.begin())
				iter--;
		} else if (t == 'D') {
			if (iter != L.end())
				iter++;
		} else if (t == 'B') {
			if (iter != L.begin())
				iter = L.erase(--iter);
				// iter = L.erase(iter);
		} else if (t == 'P') {
			cin >> t;
			L.insert(iter, t);
			//L.insert(--iter, t);
		}
	}
	for (auto&c : L) cout << c;
	return 0;
}