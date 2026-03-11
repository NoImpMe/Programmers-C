#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

string conversion(int& n, int& k){
    stack<int> st;
    string s = "";
    while( n > 0 ){
        int tmp = n % k;
        st.push(tmp);
        n /= k;
    }
    while(!st.empty()){
        s += to_string(st.top());
        st.pop();
    }
    return s;
}

bool isprime(string& s){
    if(s.size() == 0) return false;
    long long num = stoll(s);
    if(num == 1) return false;
    for(long long i = 2 ; i*i <= num ; i++){
        if(num % i == 0) return false;
    }
    return true;
}
int solution(int n, int k) {
    int answer = 0;
    string s = conversion(n, k);
    if(n == 1 || s.size() ==0){
        return 0;
    }
    string tmp = "";
    for( auto c : s){
        if(c != '0'){
            tmp += c;
        }
        else{
            if(isprime(tmp)) {
                answer++;
            }
            tmp ="";
        }
    }
    //1111111
    if(tmp.size() > 0){
        if(isprime(tmp)) {
            answer++;
        }
    }
    return answer;
}