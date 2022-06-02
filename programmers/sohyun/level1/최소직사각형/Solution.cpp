#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int width = sizes[0][0], height = sizes[0][0];
    for(int i = 0; i < sizes.size(); i++){
        for(int j = 0; j < sizes[i].size(); j++){
            if(sizes[i][j] > width)
                width = sizes[i][j];
            if(sizes[i][j] < height)
                height = sizes[i][j];
        }
    }
    for(int i = 0; i < sizes.size(); i++){
        sort(sizes[i].begin(), sizes[i].end());
    }
    for(int i = 0; i < sizes.size(); i++){
        for(int j = 0; j <sizes[i].size(); j++){
            if(height < sizes[i][0])   height = sizes[i][0];
        }
    }
    answer = width * height;
    return answer;
}