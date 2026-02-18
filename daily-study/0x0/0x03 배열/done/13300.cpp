#include <iostream>
using namespace std;

int s[7][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	while (n-- > 0) {
		int sex, grade;
		cin >> sex >> grade;
		s[grade][sex]++;
	}

	int res = 0;
	for (int i = 1; i <= 6; i++) {
		for (int j = 0; j <= 1; j++) {
			if (s[i][j])
				res += ((s[i][j]-1) / k) + 1;
		}
	}
	cout << res;
	return 0;
}