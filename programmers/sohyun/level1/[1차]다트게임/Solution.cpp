#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> step(3);
    int current_step = 1;
    auto it = dartResult.begin();
    
    while(it != dartResult.end()){
        int score = *it - '0';
        it++;
        if(*it == '0'){
            score = 10;
            it++;
        }  
        if(it == dartResult.end()) break;

        if(*it == 'S')  step[current_step-1] = score;
        else if(*it == 'D')  step[current_step-1] = pow(score, 2);
        else if(*it == 'T')  step[current_step-1] = pow(score, 3);
        it++;
        if(it == dartResult.end()) break;
        
        if(*it == '*'){
            step[current_step-1] *= 2;
            if(current_step != 1){
                step[current_step-2] *= 2; 
            }
            it++;
        }
        else if(*it == '#') {
            step[current_step-1] *= -1; 
            it++;
        }
        current_step++;
    }
    
    for(int i = 0 ; i < step.size(); i++)
        answer += step[i];
    return answer;
}