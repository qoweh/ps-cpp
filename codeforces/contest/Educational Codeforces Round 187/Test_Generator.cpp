#include <iostream>
#include <vector>

using namespace std;



int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n-- > 0) {
        int res = 0, s, m;
        vector<int> v;
        cin >> s >> m;
        if ()

        for (int i = 1; i <=m; i++) {
            if ((i & m) == i) v.push_back(i);
        }
        for (auto& c : v) cout <<c << '\n';

        
        cout << res << '\n';
    }
    return 0;
}