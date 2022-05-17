#include <string>
#include <vector>
#include <cctype>
#include <regex>
#include <iostream>
using namespace std;

string solution(string new_id) {
    string answer = "";
    
    // 1단계: 대문자-> 소문자
    for(int i = 0; i < new_id.size(); i++){
       new_id[i] = tolower(new_id[i]);
    }
    
    // 2단계: 소문자, 숫자, -, _, . 제외 모든 문자 제거
    for(auto it = new_id.begin(); it != new_id.end();){
        if(!islower(*it) && !isdigit(*it) && *it != '-' && *it != '_' && *it != '.' ){
            it = new_id.erase(it);
         }
        else{
            it++;    
        }
    }

    // 3단계: 마침표 2개이상-> 하나로 치환
    regex re("[\.]{2,}");
    new_id = regex_replace(new_id, re, ".");

    // 4단계: 마침표가 처음이나 끝에 위치 -> 제거
    if(new_id.front() == '.')   new_id.erase(0,1);
    if(new_id.back() == '.')    new_id.pop_back();
    
    // 5단계: 빈 문자열-> a 대입
    if(new_id == "") new_id.push_back('a');
    
    // 6단계: 길이 16자 이상-> 처음 15개 문자 제외 나머지 제거
    if(new_id.size() >= 16) new_id.erase(15,new_id.size()-1);
    if(new_id.back() == '.')    new_id.pop_back();
    
    // 7단계: 길이 2자 이하-> 마지막 문자 length 3이 될 때까지 끝에 붙임
    if(new_id.size() <= 2){
        while(new_id.size() != 3){
            new_id += new_id.back();

        }
    }
    answer = new_id; 
    return answer;
}