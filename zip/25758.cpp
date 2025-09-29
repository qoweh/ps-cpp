#include "../bits/stdc++.h"

using namespace std;

int n;
string arr[100000];
set<char> ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (char x = 'A'; x <= 'Z'; x++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i][0] == x) cnt++;
		}
		if (cnt > 1) {
			for (int i = 0; i < n; i++) {
				ans.insert(max(x, arr[i][1]));
			}
		}
		else if (cnt == 1) {
			for (int i = 0; i < n; i++) {
				if (arr[i][0] == x) continue;
				ans.insert(max(x, arr[i][1]));
			}
		}
	}
	cout << ans.size() << '\n';
	for (auto& x : ans) cout << x << ' ';
}