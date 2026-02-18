#include <iostream>
#include <list>

using namespace std;

void f(string& s) {
	list<char> L;
	list<char>::iterator iter = L.end(); // end()로 고정되어서 abcd 입력되면 그대로 앞에서 부터 a|, ab|, abc|, abcd| 이렇게 됨

	for (auto& c : s) {
		if (c == '-') {
			if (iter != L.begin())
				iter = L.erase(--iter);
		} else if (c == '<') {
			if (iter != L.begin())
				iter--;
		} else if (c == '>') {
			if (iter != L.end())
				iter++;
		} else {
			L.insert(iter, c);
		}
	}
	for (auto& c :L) cout << c;
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	while (n-- > 0) {
		string s;
		cin >> s;
		f(s);		
	}
	return 0;
}