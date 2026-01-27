#include <string>
#include <vector>
#include <iostream>
using namespace std;
//가장 앞에서 부터 110인 것 찾기 만약 그 뒤가 11이면 다음 110 찾기 후 우측에서 시작해서 발견된 첫 0 우측에다 삽입

vector<string> solution(vector<string> s) {
    vector<string> answer;
    for( auto str : s){
        int cnt = 0;
        if(str.size() < 3) {
            answer.push_back(str);
            continue;
        }
        string tmp;
        string oneonezero;
        oneonezero.reserve(str.size());
        for( char c : str){
            tmp.push_back(c);
            if(tmp.size() >= 3){
                if(tmp.substr(tmp.size()-3) == "110"){
                    cnt++;
                    oneonezero.append("110");
                    tmp.pop_back();
                    tmp.pop_back();
                    tmp.pop_back();
                }
            }
        }
        if (tmp.length() == 0){
            answer.push_back(oneonezero);
            continue;
        }
        if(cnt == 0){
            answer.push_back(str);
            continue;
        }
        int idx = tmp.find_last_of('0');
        if(idx != -1){
            tmp.insert(idx+1,oneonezero);
            answer.push_back(tmp);
            continue;
        }
        else{
            tmp.insert(0, oneonezero);
            answer.push_back(tmp);
        }
    }
    return answer;
}