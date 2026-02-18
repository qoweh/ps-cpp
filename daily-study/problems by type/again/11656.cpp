#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	vector<string> v;
	v.reserve(s.size());

	for (int i = s.size() - 1; i >= 0; i--) {
		v.push_back(s.substr(i));
	}
	sort(v.begin(), v.end());
	for (auto& c : v) {
		cout << c <<'\n';
	}

	
	return 0;
}