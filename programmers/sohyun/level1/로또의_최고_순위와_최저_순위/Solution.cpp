#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int high = 6, low = 6;
    int same_num = 0, zeros_num = 0; 
    
    if(lottos == win_nums){
        answer.push_back(1);
        answer.push_back(1);
        return answer;
    }
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    for(int i = 0; i < lottos.size(); i++){
        if(lottos[i] == 0)
            zeros_num++;
        for(int j = 0; j < win_nums.size(); j++){
            if(lottos[i] == win_nums[j])
                same_num++;
        }
    }
    int tmp = same_num + zeros_num;
    if(tmp == 0){
        answer.push_back(6);
        answer.push_back(6);
        return answer;
    }
    while(--tmp)
        high--;
    if(same_num){
        while(--same_num)
            low--;   
    }

    answer.push_back(high);
    answer.push_back(low);
    return answer;
}