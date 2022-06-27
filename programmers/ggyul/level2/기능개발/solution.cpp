// https://programmers.co.kr/learn/courses/30/lessons/42586
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> leftProgresses;
    for (int i = 0; i < progresses.size(); i++)
        leftProgresses.push(i);
    while (!leftProgresses.empty()) {
        for (int i = 0; i < progresses.size(); i++) {
            progresses[i] += speeds[i];
        }
        int completeCnt = 0;
        while (!leftProgresses.empty() && progresses[leftProgresses.front()] >= 100) {
            completeCnt++;
            leftProgresses.pop();
        }
        if (completeCnt != 0)
            answer.push_back(completeCnt);
    }
    return answer;
}