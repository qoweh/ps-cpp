#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	long res = 0;
	stack<int> s; 
	// n^2 시간복잡도는 시간 초과가 나올 것이 예상되니, 다른 방식으로 접근해야 함 -> k번 빌딩에서 오른쪽의 어떤 빌딩들을 '볼 수 있냐' 말고, n번 빌딩이 몇 개의 빌딩들에게 '보일 수 있느냐'를 계산. 
	// [왼쪽 빌딩이 오른쪽 빌딩보다 커야 빌딩 옥상을 볼 수 있음].
	// 스택의 역할 : 특정 빌딩의 왼쪽 빌딩들, 보여질 수 있는 (원래는 특정 빌딩에서 오른쪽 빌딩을 보아야 함.)
	cin >> n;
	
	while (n-- > 0) {
		int h;
		cin >> h;
		while (!s.empty() && s.top() <= h) {
			s.pop(); // h(현재 빌딩)에서 스택(왼쪽의 빌딩들)을 확인하며 h가 보여질 수 없다면(h가 더 크거나 같다면) 다 제거.
		}
		res += s.size();
		s.push(h);
	}
	cout << res;
	return 0;
}