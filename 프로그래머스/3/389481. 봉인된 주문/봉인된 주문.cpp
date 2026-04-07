#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
void next(string& s){
    int len = s.size()-1;
    while(true){
        if(s[len] == 'z'){
            s[len] = 'a';
            if(len == 0){
                s.insert(0,"a");
            }
            len--;
        }
        else{
            s[len] += 1;
            break;
        }
    }
}
string solution(long long n, vector<string> bans) {
    string answer = "";
    
    int ch = 97; // a = 0 알파벳 = 26개
    long long N = n;
    int len = 1;
    long long left = 0;
    while(true){
        long long tmp = 1;
        
        for(int i = 0 ; i < len ; i++) tmp *= 26;
        
        if( N > tmp){
            N -= tmp;
            len++;
        }
        else {
            left = N;
            break;
        }
    }
    string result(len, 'a');
    left--;
    for(int i = len-1 ; i >= 0; i--){
        result[i] = 'a' + (left % 26);
        left /= 26;
    }
    
    sort(bans.begin(), bans.end(), [](string& a, string& b){
        if( a.size() != b.size()) return a.size() < b.size();
        return a < b;
    });
    for(auto ban : bans){
        if(ban.size() < result.size()){
            next(result);
        }
        else if( ban.size() == result.size() && ban <= result){
            next(result);
        }
    }
    
    return result;
}