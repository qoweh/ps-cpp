#include <iostream>
using namespace std;

int n, m, arr[10];

void f(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << ' ';
		cout << '\n';
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (depth == 0 || arr[depth-1] < i) {
			arr[depth] = i;
			f(depth + 1);
		}
	}
}

int main() {
	cin >> n >> m;
	f(0);
	return 0;
}