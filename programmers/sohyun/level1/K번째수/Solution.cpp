#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands){
  vector<int> answer;
  vector<int> arr;
  for (int i = 0; i < commands.size(); i++){
    int start = commands[i][0];
    int end = commands[i][1];
    arr.assign(array.begin() + start - 1, array.begin() + end);
    sort(arr.begin(), arr.end());
    answer.push_back(arr[commands[i][2] - 1]);
  }
  return answer;
}