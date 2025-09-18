#include "../bits/stdc++.h"

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    while (n--) {
        bool f = false;
        
        string func;
        cin >> func;
        int len;
        cin >> len;
        string input;
        cin >> input;
        
        deque<int> D;
        // input에서 추출해서 D에 넣기
        input = input.substr(1, input.length() - 2);
        istringstream ss(input);
        string w;
        while (getline(ss, w, ',')) {
            D.push_back(stoi(w));
        }
        bool reverse = false;
        for (auto c : func) {
            if (c == 'R') {
                reverse = !reverse;
            } else if (c == 'D') {
                if (D.empty()) {
                    cout << "error\n";
                    f = true;
                    break;
                }
                if (reverse) D.pop_back();
                else D.pop_front();
            }
        }
        if (f) continue;
        cout << '[';
        if (reverse) {
            while (!D.empty()) {
                cout << D.back();
                if (D.size() != 1) cout << ',';
                D.pop_back();
            }
        } else {
            while (!D.empty()) {
                cout << D.front();
                if (D.size() != 1) cout << ',';
                D.pop_front();
            }
        }
        cout << ']' << '\n';
    }

    return 0;
}