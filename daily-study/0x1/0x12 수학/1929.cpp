#include "../../bits/stdc++.h"

using namespace std;

vector<bool> V(1000010, true);

void f(int last) {
	for (int i = 2; i < last; i++) {
		if (!V[i]) continue;
		// for (long long j = i + i; j <= last; j += i) {
		for (long long j = i * i; j <= last; j += i) {
			V[j] = false;
		}
	}
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

	V[1] = false;

    int m, n;
	cin >> m >> n;

	f(n);
	
	for (int i = m; i <= n; i++)
		if (V[i]) cout << i << '\n';
    return (0);
}