#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
//우측에서 시작해서 0 찾아서 1로 바꾸고 한 칸 우측 비트 0으로 변경 << 11 로 끝나는 수만 돌리면 됨? ex) ...011, ...111
//11로 끝나는 수 특징 > 4로 나눴을 때 나머지가 3

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(auto n : numbers){
        long long num = n;
        if( num % 4 == 3){
            vector<long long> tmp;
            while(num > 0){
                if( num % 2 == 0){
                    tmp.push_back(0);
                }
                else tmp.push_back(1);
                num /= 2;
            }
            tmp.push_back(0ll);
            for(int i = 0 ; i < tmp.size() ; i++){
                if(tmp[i] == 0){
                    tmp[i] = 1;
                    if(i > 1){
                        tmp[i-1] = 0;
                    }
                    break;
                }
            }
            long long num = 0;
            int idx = tmp.size()-1;
            for(int i = tmp.size()-1 ; i >= 0 ; i--){
                if(tmp[i] == 1){
                    num += pow(2, idx);
                }
                idx--;
            }
            answer.push_back(num);    
        }
        else answer.push_back(n+1);
        
    }
    return answer;
}