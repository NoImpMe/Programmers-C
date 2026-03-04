#include <string>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;

string tobinary(long long num){
    string s = "";
    stack<char> st;
    while(num > 0){
        if(num % 2 == 0){
            st.push('0');
        }
        else st.push('1');
        num /= 2;
    }
    
    int n = 1;
    while(pow(2,n) - 1 < st.size()){
        n++;
    }
    int size = pow(2,n) -1 -st.size();

    s += string(size, '0');
    
    while( !st.empty()){
        s.push_back(st.top());
        st.pop();
    }
    return s;
}
// 111 = 1101111
bool chkpreorder(const string& s, int start, int size){
    if( size == 0 ) return true;
    int mid = start + size / 2;
    if(s[mid] == '0'){
        for(int i = start ; i < start+size ; i++){
            if(s[i] == '1') return false;
        }
        return true;
    }
    return chkpreorder(s, start, size/2) && chkpreorder(s,mid+1, size /2);
    
}
vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for(int i = 0 ; i < numbers.size(); i++){
        string s = tobinary(numbers[i]);
        answer.push_back(chkpreorder(s, 0 , s.size()));
    }
    return answer;
}
