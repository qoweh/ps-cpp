#include <iostream>
#include <algorithm>
using namespace std;

int s[10];

int f(int& k) {
	while (k > 0) {
		s[k % 10]++;
		k /= 10;
	}

	s[6] = s[9] = (s[6] + s[9] + 1) / 2; 
	// 1을 더해줘서 s[6]과 s[9]의 합이 홀수일 때 반올림한다.

	return *max_element(s, s + 10);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int x;
	cin >> x;
	cout << f(x);
	return 0;
}