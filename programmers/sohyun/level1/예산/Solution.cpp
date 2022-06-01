#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
    int answer = d.size();
    int sum = 0; 
    
    sort(d.begin(), d.end());
    for(int i = 0; i < d.size(); i++){
        sum += d[i];
        if(sum > budget){
            sum -=d[i];
            answer = i;
            break;
        }
        else if(sum == budget){
            answer = i+1;
            break;
        }
    }
    return answer;
}