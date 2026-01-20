#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
int cnt = 0;
string digitalize(string s){
    int n = s.size();
    string aaa = "";
    stack<int> numstack;
    while(true){
        if(n == 0) break;
        int tmp = n % 2;
        n = n / 2;
        numstack.push(tmp);
    }
    while(!numstack.empty()){
        aaa += to_string(numstack.top());
        numstack.pop();
    }
    cnt++;
    return aaa;
}
vector<int> solution(string s) {
    vector<int> answer;
    
    int zerocnt = 0;
    int idx = 0;
    
    while(s.size() > 1){
        string tmp = "";
        for(int i = 0 ; i < s.size(); i++){
            if(s[i] == '1'){
                tmp += "1";
            }
            else{
                zerocnt++;
            }
        }
        s = digitalize(tmp);
    }
    answer.emplace_back(cnt);
    answer.emplace_back(zerocnt);
    return answer;
}