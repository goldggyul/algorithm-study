// https://programmers.co.kr/learn/courses/30/lessons/1835
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int answer = 0;
vector<string> condition;
string friends;

int getDistance(char from, char to) {
    int fromIdx = -1;
    int toIdx = -1;
    for (int i = 0; i < 8; i++) {
        if (friends[i] == from) {
            fromIdx = i;
        } else if (friends[i] == to) {
            toIdx = i;
        }
    }
    return abs(fromIdx - toIdx) - 1;
}

bool isPossible() {
    for (string d : condition) {
        char from = d[0];
        char to = d[2];
        char op = d[3];
        int dist = d[4] - '0';
        if (op == '=') {
            if (getDistance(from, to) != dist) return false;
        } else if (op == '<') {
            if (getDistance(from, to) >= dist) return false;
        } else if (op == '>') {
            if (getDistance(from, to) <= dist) return false;
        }
    }
    return true;
}

int solution(int n, vector<string> data) {
    answer = 0;
    condition = data;
    friends = "ACFJMNRT";
    
    do {
        if (isPossible())
            answer++;
    } while (next_permutation(friends.begin(), friends.end()));

    return answer;
}