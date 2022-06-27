#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    int minIdx = 0;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[minIdx] > arr[i]) minIdx = i;
    }
    arr.erase(arr.begin() + minIdx);

    if (arr.size() == 0) arr.push_back(-1);
    return arr;
}