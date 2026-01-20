#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> cnt(3,0);
    vector<int>stu1 = {1,2,3,4,5};
    vector<int>stu2 = {2,1,2,3,2,4,2,5};
    vector<int>stu3 = {3,3,1,1,2,2,4,4,5,5};
    
    for(int i = 0 ; i < answers.size(); i++){
        if(answers[i] == stu1[i%5]) cnt[0]++;
        if(answers[i] == stu2[i%8]) cnt[1]++;
        if(answers[i] == stu3[i%10]) cnt[2]++;
    }
    int max = 0;
    for(int i =0 ; i < 3; i++){
        if(cnt[i] > max) max= cnt[i];
    }
    for(int i = 0 ; i < 3; i++){
        if(cnt[i] == max) answer.emplace_back(i+1);
    }
    return answer;
}