#include <string>
using namespace std;

int solution(int num) {
    int answer = 0;
    long ln = (long)num;
    int iter = 500;
    if(ln == 1)    return 0;
    while(iter--){
        if(ln == 1)    break;
        if(ln % 2 == 0)  ln /= 2;
        else{
            ln *= 3;
            ln++;
        }
        answer++;
    }
    if(ln != 1) return -1;
    return answer;
}