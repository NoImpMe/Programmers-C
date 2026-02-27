#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    vector<string> pattern = {"zero","one", "two", "three", "four", "five","six", "seven", "eight","nine"};
    vector<string> to ={"0","1","2","3","4","5","6","7","8","9"};
    for(int i = 0 ; i < 10; i++){
        if(s.find(pattern[i]) != string::npos){
            s.replace(s.find(pattern[i]), pattern[i].length(), to[i]);
            i -=1;
        }
        
    }
    cout << s ;
    answer = stoi(s);
    return answer;
}