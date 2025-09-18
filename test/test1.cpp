#include "../bits/stdc++.h"

using namespace std;

void f(vector<char> v)
{
    for (auto k : v) cout << k << ' ';
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<char> k;
    vector<char>::iterator t;

    k.push_back('a');
    k.push_back('b');
    k.push_back('c');
    t = k.begin();
    t++;

    t = k.erase(t);
    
    f(k);

    cout << *t << '\n';

    string a = "as";
    cout << !a.compare("as") << '\n';
    return 0;
}
