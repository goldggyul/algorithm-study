#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string s = to_string(n);
    for(auto it = s.end()-1; it != s.begin()-1 ; it--)
        answer.push_back((*it) - '0');

    return answer;
}