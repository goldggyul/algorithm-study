#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    answer = arr;
    sort(arr.begin(), arr.end(), [](int a, int b){ return a > b;});
    int min = arr.back();
    auto it = find(answer.begin(), answer.end(), min);
    answer.erase(it);
    if(answer.empty())  answer.push_back(-1);
    return answer;
}