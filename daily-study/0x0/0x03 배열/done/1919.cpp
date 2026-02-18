#include <iostream>
using namespace std;

int arr['z' - 'a' + 1];

int f(string& a, string& b) {
    for (auto& c : a) arr[c - 'a']++;
    for (auto& c : b) arr[c - 'a']--;
    
    int k = 0;
    for (int i = 0; i < 'z' - 'a' + 1; i++) k += abs(arr[i]);
    return k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s1, s2;
	cin >> s1 >> s2;
	cout << f(s1, s2);
	return 0;
}