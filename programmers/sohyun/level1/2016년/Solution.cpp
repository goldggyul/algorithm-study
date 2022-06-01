#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int dis = 0;
    switch(a){
        case 1:
            dis = b - 1;
            break;
        case 2:
            dis = 31 + b - 1;
            break;
        case 3:
            dis = 31 + 29 + b - 1;
            break;
        case 4: 
            dis = 31*2 + 29 + b - 1;
            break;
        case 5: 
            dis = 31*2 + 29 + 30 + b - 1;
            break;
        case 6:
            dis = 31*3 + 29 + 30 + b - 1;
            break;
        case 7:
            dis = 31*3 + 29 + 30*2 + b - 1;
            break;
        case 8:
            dis = 31*4 + 29 + 30*2 + b - 1;
            break;
        case 9:
            dis = 31*5 + 29 + 30*2 + b - 1;
            break;
        case 10:
            dis = 31*5 + 29 + 30*3 + b - 1;
            break;
        case 11:
            dis = 31*6 + 29 + 30*3 + b - 1;
            break;
        case 12: 
            dis = 31*6 + 29 + 30*4 + b - 1;
            break;
    }
    switch(dis%7){
        case 0:
            answer = "FRI";
            break;
        case 1:
            answer = "SAT";
            break;
        case 2: 
            answer = "SUN";
            break;
        case 3:
            answer = "MON";
            break;
        case 4:
            answer = "TUE";
            break;
        case 5:
            answer = "WED";
            break;
        case 6:
            answer = "THU";
            break;
    }
    return answer;
}