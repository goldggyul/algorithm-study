// https://programmers.co.kr/learn/courses/30/lessons/77485
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int flagX[4];
int flagY[4];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
vector<vector<int>> matrix;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    // 초기 행렬
    matrix.resize(rows, vector<int>(columns));
    int cnt = 0;
    while (cnt < rows * columns) {
        matrix[cnt / columns][cnt % columns] = cnt + 1;
        cnt++;
    }

    for (auto& query : queries) {
        int fromX = query[0] - 1;
        int fromY = query[1] - 1;
        int toX = query[2] - 1;
        int toY = query[3] - 1;

        // 각 방향 회전에서 마지막 위치 저장
        flagX[0] = fromX; flagY[0] = toY;
        flagX[1] = toX; flagY[1] = toY;
        flagX[2] = toX; flagY[2] = fromY;
        flagX[3] = fromX; flagY[3] = fromY;

        // 회전
        int cache = matrix[fromX][fromY];
        int minAns = cache;
        // 맨 처음 시작 위치
        int x = fromX;
        int y = fromY;
        for (int i = 0; i < 4; i++) {
            while (x != flagX[i] || y != flagY[i]) {
                x += dx[i];
                y += dy[i];

                int temp = cache;
                cache = matrix[x][y];
                matrix[x][y] = temp;
                minAns = min(minAns, cache);
            }
        }
        answer.push_back(minAns);
    }
    return answer;
}