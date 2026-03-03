#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int f(string x) {
    int t = 0;
    for (auto& c : x) {
        t += + c - '0';
    }
    return t;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n-- > 0) {
        string x;
        int res = 0, arr[10] = {};
        cin >> x;
        
        int sum_x = f(x);
        for (auto c : x) arr[c - '0']++;
        int first = x[0] - '0';
        
        while (sum_x >= 10) {
            for (int i = 9; i >= 0; i--) {
                if (arr[i] != 0) {
                    if (arr[i] == 1 && i == first)
                        sum_x -= i-1;
                    else sum_x -= i;
                    arr[i]--;
                    break;
                }
            }            
            res++;
        }
        cout << res << '\n';
    }
    return 0;
}

/* 
*****************
*****************
***gpt's solve***
*****************
*****************

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string x;
        cin >> x;

        int sum = 0;
        vector<int> reduce;

        for (int i = 0; i < x.size(); i++) {
            int d = x[i] - '0';
            sum += d;

            if (i == 0) reduce.push_back(d - 1); // 첫 자리
            else reduce.push_back(d);
        }

        if (sum <= 9) {
            cout << 0 << '\n';
            continue;
        }

        sort(reduce.rbegin(), reduce.rend());

        int need = sum - 9;
        int res = 0;

        for (int r : reduce) {
            need -= r;
            res++;
            if (need <= 0) break;
        }

        cout << res << '\n';
    }
}

*/