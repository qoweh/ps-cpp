#include "../bits/stdc++.h"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    string s;
    stack<int> S;
    vector<int> P;

    // 입력
    while (1) {
        getline(cin, s);
        stringstream ss(s);
        while (ss >> s) {
            S.push(stoi(s));
        }
        if (S.size() == 1 && S.top() == 0)
            break;

        // 알고리즘
        int i = 0, m = 0;
        // 하나씩 빼면서 
        while (!S.empty()) {
            i++;



            S.pop();
        }
        
    }


    // 출력
    for (auto k : P) cout << k << '\n';
    
    return 0;
}