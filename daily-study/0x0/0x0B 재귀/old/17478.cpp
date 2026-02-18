#include "../bits/stdc++.h"

using namespace std;

int n;
string first = "\"재귀함수가 뭔가요?\"";
string last_case = "\"재귀함수는 자기 자신을 호출하는 함수라네\"";
string last = "라고 답변하였지.";
string str[] = {
    first,
    "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.",
    "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.",
    "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\""
};

void under_bar_cout(int n) {
    string under_bar = "____";
    for (int i = 0; i < n; i++)
        cout << under_bar;
}

void f1(int k) {
    if (k == n) {
        for (string s : {first, last_case}) {
            under_bar_cout(k);
            cout << s << '\n';
        }
        return ;
    }
    for (string s : str) {
        under_bar_cout(k);
        cout << s << '\n';
    }
    f1(k + 1);
}

void f2(int k) {
    if (k == 0) {
        cout << last;
        return ;
    }
    under_bar_cout(k);
    cout << last << '\n';
    f2(k - 1);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    f1(0);
    f2(n);
    return 0;
}


// ____
// ________
// ________