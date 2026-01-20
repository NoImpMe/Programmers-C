#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if(n >s) {
        answer.emplace_back(-1);
        return answer;
    }
    int num = n;
    for(int i = 0  ; i < num ; i++){
        answer.emplace_back(s / n);
        s -= s / n;
        n -= 1;
        if(s <= 0) break; 
    }
    return answer;
}