#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

bool IsFactor(int a){
    if(a == 0 || a == 1) return false;
    for(int i = 2 ; i <= a/2 ; i++){
        if(a % i == 0)
            return false;
    }
    return true;
}
int solution(string numbers) {
    set<int> s;
    sort(numbers.begin(), numbers.end());
    int answer = 0;
    for(int i = 1 ; i <= numbers.size(); i++){
        vector<bool> v(numbers.size()-i, false);
        v.insert(v.end(),i,true);
        do{
            string tmp = "";
            for(int j = 0 ; j < numbers.size() ; j++){
                if(v[j]) tmp += numbers[j];
            }
            if(tmp.size() > 1){
                do{
                    string temp = "";
                    for(int k = 0 ; k < tmp.size() ; k++){
                        temp += tmp[k];
                    }
                    s.insert(stoi(temp));
                }while(next_permutation(tmp.begin(), tmp.end()));
            }
            s.insert(stoi(tmp));
        }while(next_permutation(v.begin(), v.end()));
    }
    for( auto &i : s){
        
        if(IsFactor(i)) {
            answer++;
        }
    }
    return answer;
}