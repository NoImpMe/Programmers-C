#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    vector<vector<int>> pairs =
    {
        {0,1,2,3},
        {0,2,1,3},
        {0,3,1,2}
    };
    for(auto i : pairs){
        float rldnf1 = (float)(dots[i[0]][1] - dots[i[1]][1]) / (dots[i[0]][0]-dots[i[1]][0]);
        float rldnf2 = (float)(dots[i[2]][1] - dots[i[3]][1]) / (dots[i[2]][0]-dots[i[3]][0]);
        if(rldnf1 == rldnf2) return 1;  
    }
    return answer;
}