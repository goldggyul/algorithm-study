#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string s1, string s2, int n){
    if(s1[n] == s2[n])  return s1 < s2;
    return s1[n] < s2[n];
}
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    sort(strings.begin(), strings.end(), bind(comp,std::placeholders::_1,std::placeholders::_2,n));
    answer = strings;
    return answer;
}