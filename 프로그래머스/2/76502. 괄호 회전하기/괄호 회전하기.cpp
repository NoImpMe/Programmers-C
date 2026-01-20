#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;
    for(int i = 0 ; i < s.length(); i++){
        string tmp = s.substr(i) + s.substr(0, i);
        stack<char> s;
        for(int j = 0 ; j < tmp.length(); j++){
            if( tmp[j] == '[' || tmp[j] == '(' || tmp[j] == '{' || s.empty()){
                s.push(tmp[j]);
            }
            else {
                if(s.top() ==']' || s.top() == ')' || s.top() == '}'){
                    break;
                }
                else if(s.top() == '['){
                    if(tmp[j] == ']'){
                        s.pop();
                    }
                }
                else if(s.top() == '('){
                    if(tmp[j] == ')'){
                        s.pop();
                    }
                }
                else if(s.top() == '{'){
                    if(tmp[j] == '}'){
                        s.pop();
                    }
                }
                else {
                    s.push(tmp[j]);
                }
            }
        }
        if(s.empty()) answer++;
    }
    
    return answer;
}