#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int month[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    string dayOfWeek[] ={"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    int dis = 0;
    for(int i = 0; i < a; i++){
        dis += month[i];
    }
    dis = dis + b - 1; 
    answer = dayOfWeek[dis % 7];
    
    return answer;
}