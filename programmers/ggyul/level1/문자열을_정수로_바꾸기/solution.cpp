#include <string>
#include <sstream>

using namespace std;

int solution(string s) {
    stringstream ss(s);
    int answer;
    ss >> answer;
    return answer;
}