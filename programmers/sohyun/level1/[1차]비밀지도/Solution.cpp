#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    for(int i = 0; i < n; i++){
        string code = "";
        while(code.size() != n){
            code += (arr1[i] % 2 != 1 && arr2[i] % 2 != 1) ? " " : "#";
            arr1[i] /= 2;
            arr2[i] /= 2; 
        }
        reverse(code.begin(), code.end());
        answer[i] = code;  
    }
    return answer;
}