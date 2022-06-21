// https://programmers.co.kr/learn/courses/30/lessons/1829
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<vector<bool>> visited(m, vector<bool>(n));

    int dx[4] = { 0,1,0,-1 };
    int dy[4] = { 1,0,-1,0 };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && picture[i][j] > 0) {
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                int area = 0;
                while (!q.empty()) {
                    pair<int, int> cur = q.front(); q.pop();
                    int x = cur.first, y = cur.second;
                    if (x < 0 || x >= m || y < 0 || y >= n
                        || visited[x][y] || picture[i][j] != picture[x][y])
                        continue;
                    visited[x][y] = true;
                    area++;
                    for (int d = 0; d < 4; d++) {
                        q.push(make_pair(x + dx[d], y + dy[d]));
                    }
                }
                if (max_size_of_one_area < area) max_size_of_one_area = area;
                number_of_area++;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}