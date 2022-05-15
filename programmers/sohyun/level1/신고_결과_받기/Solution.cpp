#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k){
  vector<int> answer(id_list.size(), 0);

  map<string, vector<string> > rm;

  string from = "";
  string to = "";
  for (int i; i < report.size(); i++){
    from = report[i].substr(0, report[i].find(" "));
    to = report[i].substr(report[i].find(" ") + 1, report[i].length());

    auto it = rm.find(to);
    if (it != rm.end()){ //키 값이 있으면
      bool isIn = false;
      for (string i : it->second){
        if (i == from){
          // 중복제거
          isIn = true;
          break;
        }
      }
      if (!isIn){
        rm[to].push_back(from);
      }
    }
    else{ // 키 값 없을 때 바로 저장
      rm[to].push_back(from);
    }
  }
  for (const auto &p : rm){
    if (p.second.size() >= k){
      for (int i = 0; i < id_list.size(); i++){
        for (int j = 0; j < p.second.size(); j++){
          if (p.second[j] == id_list[i]){
            answer[i]++;
          }
        }
      }
    }
  }

  return answer;
}