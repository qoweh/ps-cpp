#include "../bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<pair<int, int>> meetings(n);
    
    for (int i = 0; i < n; i++) {
        cin >> meetings[i].first >> meetings[i].second; // (start, end)
    }
    
    // 핵심: 끝나는 시간(second) 기준으로 정렬!
    sort(meetings.begin(), meetings.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        return a.second < b.second;  // 끝나는 시간이 빠른 순
    });
    
    cout << "끝나는 시간 기준 정렬 결과:\n";
    for (int i = 0; i < n; i++) {
        cout << "회의 " << i << ": [" << meetings[i].first << ", " << meetings[i].second << ")\n";
    }
    cout << "\n";
    
    // 그리디 선택: 앞에서부터 겹치지 않는 것만 선택
    int count = 0;
    int lastEnd = 0;  // 마지막으로 선택한 회의의 끝시간
    
    cout << "선택 과정:\n";
    for (int i = 0; i < n; i++) {
        int start = meetings[i].first;
        int end = meetings[i].second;
        
        if (start >= lastEnd) {  // 겹치지 않으면 선택!
            cout << "회의 [" << start << ", " << end << ") 선택! (총 " << (count + 1) << "개)\n";
            lastEnd = end;
            count++;
        } else {
            cout << "회의 [" << start << ", " << end << ") 건너뜀 (겹침: " << start << " < " << lastEnd << ")\n";
        }
    }
    
    cout << "\n최대 회의 수: " << count << endl;
    return 0;
}