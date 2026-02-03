#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int s[] = {0, 
		31, 28, 31, 
		30, 31, 30, 
		31, 31, 30, 
		31, 30, 31};
	string days[] = {
		"MON", "TUE", "WED", "THU", "FRI", 
		"SAT" ,"SUN"};
	int x, y, total_day = 0;

	cin >> x >> y;
	for (int i = 1; i < x; i++) {
		total_day += s[i];
	}
	total_day += y - 1;
	cout << days[total_day % 7];
	return 0;
}