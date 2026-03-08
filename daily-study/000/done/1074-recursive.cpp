#include <iostream>
using namespace std;

int f(int power, int r, int c) {
	if (power == 0) return 0;

	int len = (1 << power);
	int half = len / 2;
	
	//왼쪽 위 채우기
	if (r < half && c < half) {
		return f(power-1, r % half, c % half) + half * half * 0;
	}
	//오른쪽 위 채우기
	else if (r < half && c >= half) {
		return f(power-1, r % half, c % half) + half * half * 1;
	}
	//왼쪽 아래 채우기
	else if (r >= half && c < half) {
		return f(power-1, r % half, c % half) + half * half * 2;
	}
	//오른쪽 아래 채우기
	else {
		return f(power-1, r % half, c % half) + half * half * 3;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, r, c;	
	cin >> n >> r >> c;
	cout << f(n, r, c);
	return 0;
}