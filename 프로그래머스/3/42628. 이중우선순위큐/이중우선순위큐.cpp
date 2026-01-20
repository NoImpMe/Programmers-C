#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    set<int> s;
    for( auto cmd : operations){
        if(cmd[0] == 'I'){
            string num = cmd.substr(2, cmd.size());
            int txtnum = stoi(num);
            s.emplace(txtnum);
        }
        else if(cmd[2] == '-'){
            if(s.empty()) continue;
            s.erase(*s.begin());

        }
        else if(cmd[2] == '1'){
            if(s.empty()) continue;
            s.erase(*s.rbegin());
        }
    }
    if(s.empty()) answer = {0,0};
    else answer = {*s.rbegin(), *s.begin()};
    return answer;
}