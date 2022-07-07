// https://school.programmers.co.kr/learn/courses/30/lessons/72411
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool comp(pair<string, int>& l, pair<string, int>& r) {
    return l.second > r.second;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    map<string, int> menuMap;
    for (int i = 0; i < orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());
        for (int cnt : course) {
            if (orders[i].size() < cnt) continue;
            string comb(orders[i].size(), '0');
            for (int j = 0; j < cnt; j++) comb[j] = '1'; // 11000 형태로 채움
            do {
                string s = "";
                for (int j = 0; j < comb.size(); j++) {
                    if (comb[j] == '1') {
                        s.push_back(orders[i][j]);
                    }
                }
                menuMap[s]++;
                // 1부터 시작했으므로 prev_permutation 사용
            } while (prev_permutation(comb.begin(), comb.end()));
        }
    }

    vector<pair<string, int>> menus(menuMap.begin(), menuMap.end());
    sort(menus.begin(), menus.end(), comp);
    for (int cnt : course) {
        int mxCnt = 0;
        for (auto it = menus.begin(); it != menus.end(); it++) {
            if (it->first.size() == cnt && it->second >= 2) {
                if (mxCnt > it->second) break;
                if (mxCnt == 0) mxCnt = it->second;
                answer.push_back(it->first);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}