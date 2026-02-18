#include "../bits/stdc++.h"
using namespace std;

int func2(int arr[], int n) {
  int s[101] = {};
  for (int i = 0; i < n; i++) {
    if (s[100 - arr[i]] == 1)
      return 1;
    s[arr[i]] = 1;
  }
  return 0;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int arr1[] = {1, 52, 48};
  int arr2[] = {50, 42};
  int arr3[] = {4, 13, 67, 87};

  if (func2(arr1, 3) == 1) cout << "참1" << '\n';
  if (func2(arr2, 2) == 0) cout << "참2" << '\n';
  if (func2(arr3, 4) == 1) cout << "참3" << '\n';
  return 0;
}

/*!SECTION

0 1 2 3 4 ... n-1


*/