/// https://school.programmers.co.kr/learn/courses/30/lessons/17677
#include <string>
#include <cctype>
#include <set>
#include <algorithm>
using namespace std;

multiset<string> getMultiset(string str) {
    multiset<string> res;
    for (int i = 0; i < str.size() - 1; i++) {
        if (isalpha(str[i]) && isalpha(str[i + 1])) {
            string s = str.substr(i, 2);
            if (islower(s[0])) s[0] = toupper(s[0]);
            if (islower(s[1])) s[1] = toupper(s[1]);
            res.insert(s);
        }
    }
    return res;
}

int solution(string str1, string str2) {
    // 1. 각 문자의 집합 만들기
    multiset<string> set1 = getMultiset(str1);
    multiset<string> set2 = getMultiset(str2);

    if (set1.empty() && set2.empty()) {
        // 둘다 공집합일 경우 1
        return 65536;
    }
    // 2. 교집합 구하기
    multiset<string> inter;
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(inter, inter.begin()));
    int result = ((double)inter.size() / (set1.size() + set2.size() - inter.size())) * 65536;
    return result;
}