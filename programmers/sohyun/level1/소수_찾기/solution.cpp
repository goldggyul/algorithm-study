#include <string>
#include <vector>
#include <cmath>
using namespace std;


int solution(int n) {
    int answer = 0;
    vector<bool> isPrime;
    for(int i = 0; i <= n; i++)
        isPrime.push_back(true);
 
    for(int i = 2; i <= sqrt(n) ; i++){
        if(isPrime[i]){
            for(int j = i*i; j <= n ; j += i){
                if(isPrime[j]){
                    isPrime[j] = false;
                    answer++; // 소수가 아닌 수의 개수
                }
                
            }
        }
    }
   
    return n-answer-1;
}