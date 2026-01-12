#include "../bits/stdc++.h"

using namespace std;

int main(void) {
    list<int> L = {1, 2};
    list<int>::iterator t = L.begin(); // t는 1을 가리키는 중

    L.push_front(10); // 10 1 2
    
    cout << "here " << *t << '\n'; // t가 가리키는 값 = 1을 출력
    
    L.push_back(5); // 10 1 2 5
    L.insert(t, 6); // t가 가리키는 곳 앞에 6을 삽입, 10 6 1 2 5

    cout << "here " << *t << '\n'; // t가 가리키는 값 = 1을 출력
    
    t++; // t를 1칸 앞으로 전진, 현재 t가 가리키는 값은 2

    cout << "here " << *t << '\n'; // t가 가리키는 값 = 2을 출력
    
    t++; // t를 1칸 앞으로 전진, 현재 t가 가리키는 값은 5

    cout << "here " << *t << '\n'; // t가 가리키는 값 = 5을 출력
    
    t = L.erase(t); // t가 가리키는 값을 제거, 그 다음 원소인 ?의 위치를 반환
                    // 10 6 1 5, t가 가리키는 값은 ?
    
    cout << *t << '\n'; // 5


    // 출력 방법 다양함 + for문으로 원소 값 수정 가능


    for (auto i : L) cout << i << ' ';
    cout << '\n';

    for (auto& i : L) {
        i = i + 1;
        cout << i << ' ';
    }
        
    cout << '\n';

    for (list<int>::iterator it = L.begin(); it != L.end(); it++) {
        *it = *it + 1;
        cout << *it << ' ';
    }

    return 0;
}