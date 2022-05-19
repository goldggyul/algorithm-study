#include <string>
#include <vector>

using namespace std;

string direction(int n){
    if(n == 1 || n == 4 || n == 7)
        return "L";
    if(n == 3 || n == 6 || n == 9)
        return "R";
    return "O";
}

int distance(int a, int b){
    if(b == 2){
        if(a == 2)  return 0;
        if(a == 5)  return 1;
        if(a == 8)  return 2;
        if(a == 0)  return 3;
    }
    if(b == 5){
        if(a == 2)  return 1;
        if(a == 5)  return 0;
        if(a == 8)  return 1;
        if(a == 0)  return 2;
    }
    if(b == 8){
        if(a == 2)  return 2;
        if(a == 5)  return 1;
        if(a == 8)  return 0;
        if(a == 0)  return 1;
    }
    if(b == 0){
        if(a == 2)  return 3;
        if(a == 5)  return 2;
        if(a == 8)  return 1;
        if(a == 0)  return 0;
    }
    if(b == 1 || b == 3){
        if(a == 2)  return 1;
        if(a == 5)  return 2;
        if(a == 8)  return 3;
        if(a == 0)  return 4;
    }
    if(b == 4 || b == 6){
        if(a == 2)  return 2;
        if(a == 5)  return 1;
        if(a == 8)  return 2;
        if(a == 0)  return 3;
    }
    if(b == 7 || b == 9){
        if(a == 2)  return 3;
        if(a == 5)  return 2;
        if(a == 8)  return 1;
        if(a == 0)  return 2;
    }
    if(b == -1){
        if(a == 2)  return 4;
        if(a == 5)  return 3;
        if(a == 8)  return 2;
        if(a == 0)  return 1;
    }
   
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = -1, right = -1; 
    for(int i = 0; i < numbers.size(); i++){
        if(direction(numbers[i]) == "O"){
            int dis = distance(numbers[i],left) - distance(numbers[i],right); 
            if(dis == 0){
                if(hand == "left"){
                    left = numbers[i];
                    answer += "L";
                }
                else{
                    right = numbers[i];
                    answer += "R";
                }
            }
            else if(dis > 0){
                right = numbers[i];
                answer += "R";
            }
            else if(dis < 0){
                left = numbers[i];
                answer += "L";
            }
        }
        else{
            answer += direction(numbers[i]);
            if(direction(numbers[i]) == "L")    left = numbers[i];
            else    right = numbers[i];
        }    
    }
    
    
    return answer;
}