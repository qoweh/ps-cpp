#include <iostream>
using namespace std;

long long f(int a, int b, int c) {
	if (b <= 1) return a % c;
	long long t = f(a, b/2, c);
	if (b % 2 == 1) return (((t * t) % c) * a) % c;
	return ((t * t) % c);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int a, b, c;
	cin >> a >> b >> c;
	cout << f(a, b, c);
	return 0;
}