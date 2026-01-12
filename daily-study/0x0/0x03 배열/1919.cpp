#include "../bits/stdc++.h"
using namespace std;

int s1['z' - 'a' + 1];
int s2['z' - 'a' + 1];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int answer = 0;
    string a, b;
    cin >> a >> b;
    for (char c : a) s1[c - 'a']++;
    for (char c : b) s2[c - 'a']++;
    for (int i = 0; i < 'z' - 'a' + 1; i++)
        if (s1[i] != s2[i])
            answer += abs(s1[i] - s2[i]);
    cout << answer << '\n';
    return 0;
}