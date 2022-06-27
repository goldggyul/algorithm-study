#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
3진법인데 0,1,2,3,... 대신 1,2,3,4..를 바꾼다
따라서 1, 2, 3,.. 대신 1을 빼서 0, 1, 2,...로 바꾸고 3을 나눈 뒤
나머지 0, 1, 2 대신에 1, 2, 4로 변환한다
*/

string solution(int n) {
    string answer = "";
    while (n > 0) {
        n -= 1;
        int r = n % 3;
        answer = "124"[r] + answer;
        n /= 3;
    }
    return answer;
}