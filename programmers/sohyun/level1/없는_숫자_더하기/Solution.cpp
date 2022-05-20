#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = -1;
    int sum = 0;
    for(int n : numbers)
        sum += n;
    answer =  45 - sum;
    return answer;
}