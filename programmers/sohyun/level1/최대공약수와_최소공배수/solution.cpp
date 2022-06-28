#include <string>
#include <vector>

using namespace std;

int getGcd(int a, int b){
    vector<int> divisor1;
    vector<int> divisor2;
    vector<int> cd;
    for(int i = 1; i <= a; i++){
        if(a % i == 0)  divisor1.push_back(i);
    }
     for(int i = 1; i <= b; i++){
        if(b % i == 0)  divisor2.push_back(i);
    }
    for(int i = 0; i < divisor1.size(); i++){
        for(int j = 0; j < divisor2.size(); j++){
            if(divisor1[i] == divisor2[j]){
                cd.push_back(divisor1[i]);
            }
        }
    }
    return cd.back();

}

int getLcm(int a, int b){
    int max = a > b? a : b;
    int min = a < b? a : b;
    for(int i = 1; i <= max; i++){
        if((min * i) % max == 0)    return min * i;
    }
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    answer.push_back(getGcd(n, m));
    answer.push_back(getLcm(n, m));
    return answer;
}