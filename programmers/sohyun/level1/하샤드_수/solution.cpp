#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int sum = 0;
    int n = x;
    while(x){
        sum += x % 10;
        x /= 10;
    }
    if(n % sum) answer = false;
    return answer;
}