// https://programmers.co.kr/learn/courses/30/lessons/42626
/*
처음에 '가장 낮은' 두 개 뽑는거인줄 모르고
최대한 적게 뽑는 방법 생각해서 구현했는데 (deque, priority_queue)
계속 틀려서 이상해서 답 보니까
가장 낮은 두 개 뽑는거였다..
문제 잘 읽기....
*/
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int s : scoville)
        q.push(s);
    while (!q.empty()) {
        int first = q.top(); q.pop();
        if (first >= K) break;
        if (q.empty()) {
            answer = -1;
            break;
        }
        int second = q.top(); q.pop();
        q.push(first + second * 2);
        answer++;
    }
    return answer;
}