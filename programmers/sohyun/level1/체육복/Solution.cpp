#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve){
  int answer = 0;
  sort(lost.begin(), lost.end());
  sort(reserve.begin(), reserve.end());

  vector<bool> from(reserve.size(), false);
  vector<bool> to(lost.size(), false);
  set<int> s;

  for (int i = 0; i < lost.size(); i++){
    for (int j = 0; j < reserve.size(); j++){
      if (lost[i] == reserve[j]){
        from[j] = true;
        to[i] = true;
        s.insert(lost[i]);
      }
    }
  }
  for (int i = 0; i < lost.size(); i++){
    for (int j = 0; j < reserve.size(); j++){
      if (!from[j] && !to[i]){
        if (reserve[j] - 1 == lost[i] || reserve[j] + 1 == lost[i]){
          from[j] = true;
          to[i] = true;
          s.insert(lost[i]);
          break;
        }
      }
    }
  }

  int losted_cnt = lost.size() - s.size();
  answer = n - losted_cnt;

  return answer;
}