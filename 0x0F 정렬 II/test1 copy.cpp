#include "../bits/stdc++.h"

using namespace std;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 'A'; i <= 'Z'; i++) {
        cout << char(i) << ":" << i << '\n';
    }

    for (int i = '0'; i <= '9'; i++) {
        cout << char(i) << ":" << i << '\n';
    }
    

    return 0;
}