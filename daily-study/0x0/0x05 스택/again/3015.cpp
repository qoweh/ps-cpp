#include <iostream>
#include <stack>

#define X first
#define Y second
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	stack<pair<int, int>> s;
	long long ans = 0;
	int n;
  	cin >> n;

  	while (n--) {
		int h;
		cin >> h;
		int cnt = 1;
		
		while (!s.empty() && s.top().X <= h) {
			ans += s.top().Y;
			if (s.top().X == h) cnt += s.top().Y;
			s.pop();
		}
		if (!s.empty()) ans++;
		s.push({h, cnt});
	}
 	cout << ans;
}