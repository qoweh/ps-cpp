#include "../bits/stdc++.h"
using namespace std;

int arr['z' -'a' + 1];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  for (auto c : s) arr[c - 'a']++;
  for (int v : arr) cout << v << ' ';
  return 0;
}