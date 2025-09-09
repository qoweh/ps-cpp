#include "../bits/stdc++.h"
using namespace std;
bool is_num(char k)
{
    return ('0' <= k && k <= '9');
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string init;
    stack<int> S;
    bool flag = false;
    int answer = 0;

    cin >> init;
    for (auto a : init)
    {
        if (flag) break;
        if (a == '[' || a == '(') S.push(a);
        else if (a == ']' || a == ')')
        {
            if (S.empty())
            {
                flag = true;
                break;
            }
            int num = 0;
            while (is_num(S.top()))
            {
                num += (S.top() - '0');
                S.pop();
            }
            int fair = a - S.top();
            if (fair == 1 || fair == 2) // fair 값 : () -> 1, [] -> 2
            {
                S.pop();
                S.push((fair + 1) * (num != 0 ? num : 1));
            }
            else flag = true;
        }
    }
    if (is_num(S.top()))
    {
        answer = S.top() - '0';
        S.pop();
    }
    if (!S.empty()) flag = true;
    if (flag) cout << 0;
    cout << answer;
    return 0;
}
// [ : 91, ] : 93, ( : 40, ) : 41 -> fair가 1, 2 값이어야 옳은 경우
// fiar가 1 : (), 2 : []