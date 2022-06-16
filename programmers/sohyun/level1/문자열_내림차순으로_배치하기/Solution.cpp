#include <string>
#include <vector>
#include <algorithm>
using namespace std;


string solution(string s) {
    string answer = "";
    sort(s.begin(), s.end(), [](char c1, char c2) { return c1 > c2;});
    answer = s;
    return answer;
}