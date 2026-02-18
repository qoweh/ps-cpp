#include "../bits/stdc++.h"

using namespace std;

int n;
vector<string> V;

bool cmp1(string a, string b) {
    return a.size() < b.size();
}

bool cmp2(string a, string b) {
    int a1 = 0;
    for (char c : a) {
        if ('0' <= c && c <= '9') a1 += c - '0';
    }
    int b1 = 0;
    for (char c : b) {
        if ('0' <= c && c <= '9') b1 += c - '0';
    }
    return a1 < b1;
}

bool cmp3(string a, string b) {
    int i = 0;
    while (i < a.size()) {
        if (a[i] < b[i]) return true;
        else if (a[i] > b[i]) false;
        else i++;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        V.push_back(s);
    }
    sort(V.begin(), V.end(), cmp1);
    sort(V.begin(), V.end(), cmp2);
    sort(V.begin(), V.end(), cmp3);

    for (auto v : V) {
        cout << v << '\n';
    }

    return 0;
}