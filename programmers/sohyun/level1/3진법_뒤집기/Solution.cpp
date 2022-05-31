#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> reverse;
    while(true){
        if(n < 3){
            reverse.push_back(n);
            break;
        }
        if(n / 3 <= 2){
            reverse.push_back(n % 3);
            reverse.push_back(n / 3);
            break;
        }
        reverse.push_back(n % 3);
        n /= 3; 
    }
    for(int i = 0; i < reverse.size(); i++){
        answer += reverse[i] * pow(3, reverse.size() - (i + 1));
    }
    return answer;
}