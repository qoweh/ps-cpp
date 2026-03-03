#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int reps;
    cin >> reps;
    while (reps-- > 0) {
        int n, m, d, temp = 0;
        cin >> n >> m >> d;
        int t = d / m + 1;
        int res = ceil((float)n / t);
        cout << res << '\n';
    }
    return 0;
}