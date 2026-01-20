#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    long long ahrt = 0;
    long long skajwl = 0;
    for(long long tmp = left+1 ; tmp <= right+1 ; tmp++){
        ahrt = tmp / n;
        skajwl = tmp % n;
        if( skajwl == 0 ) answer.emplace_back(n);
        else if( ahrt < skajwl ) answer.emplace_back(skajwl);
        else answer.emplace_back(ahrt+1);
        
    }
    return answer;
}