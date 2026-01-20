#include <string>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
string three(int n){
    stack<int> s;
    while(n != 0){
        s.push(n%3);
        n /= 3;
    }
    string tmp = "";
    while(!s.empty()){
        tmp += to_string(s.top());
        s.pop();
    }
    return tmp;
}

int solution(int n) {
    int answer = 0;
    string res = three(n);
    for(int i = res.size() -1 ; i >=0 ; i--){
        answer += (res[i]-'0') * pow(3,i);
    }
    return answer;
}