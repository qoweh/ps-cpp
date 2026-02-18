#include <iostream>
using namespace std;

bool s[2000010];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, t, x, res = 0;

	fill(s, s + 2000010, false);

	cin >> n;
	while (n-- > 0) {
		cin >> t;
		s[t] = true;
	}
	cin >> x;

	for (int i = 1; i <= ((x+1) / 2) - 1; i++) {
		if (s[i] && s[x-i])
			res++;
	}
	cout << res;
	return 0;
}