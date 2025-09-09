#include "../bits/stdc++.h"
using namespace std;

int main(void)
{
    ios::sync_with_stdio(1);
    cin.tie(0);

    string init;
    while (true)
    {
        getline(cin, init);
        if (init == ".") break;
        stack<int> S;
        cout << init << ": ";
        for (auto a : init)
        {
            S.push((int)a);
            cout << "S.top(): " << S.top() << '\n';
            cout << "a: " << a << ' ';
            cout << "(char)a: " << (char)a << ' ';
        }
        cout << '\n';
        
    }
    int i = 0;
    while (true)
    {
        if (i >= 10)
        {
            if (i == 14)
                break;
        }
        cout << i++ << " ";
    }
    return 0;
}