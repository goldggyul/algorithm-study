#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    string s = to_string(n);
    sort(s.begin(),s.end(),[](char c1, char c2){return c1 > c2;});
    answer = stoll(s);
    return answer;
}