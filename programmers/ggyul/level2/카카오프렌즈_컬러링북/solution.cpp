// https://programmers.co.kr/learn/courses/30/lessons/1829
#include <vector>
#include <iostream>
using namespace std;

int m;
int n;
vector<vector<int>> picture;

int dx[4] = { 0,1,0,-1 }; // 오른쪽, 아래, 왼쪽, 위
int dy[4] = { 1,0,-1,0 };
bool visited[105][105];

int dfs(int i, int j, int color) {
    if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || picture[i][j] != color) {
        return 0;
    }
    visited[i][j] = true;
    int sum = 0;
    for (int d = 0; d < 4; d++) {
        sum += dfs(i + dx[d], j + dy[d], color);
    }
    return sum + 1;
}

vector<int> solution(int _m, int _n, vector<vector<int>> _picture) {
    m = _m;
    n = _n;
    picture = _picture;

    int number_of_area = 0;
    int max_size_of_one_area = 0;

    fill(&visited[0][0], &visited[m - 1][n], false);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && picture[i][j] > 0) {
                int sum = dfs(i, j, picture[i][j]);
                number_of_area++;
                if (sum > max_size_of_one_area) max_size_of_one_area = sum;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}