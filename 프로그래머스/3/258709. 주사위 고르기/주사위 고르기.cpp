#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> cases;
vector<vector<int>> reversecases;
vector<vector<int>> casesofdice;
vector<int> tmpcase;
vector<int> tmpdice;

void combine(int n, int r, int start){
    if(tmpcase.size() == r){
        cases.push_back(tmpcase);
        int j = 0;
        vector<int> reversecase;
        for(int i = 0 ; i < n; i++){
            if(i != tmpcase[j]){
                reversecase.push_back(i);
                if(reversecase.size() == r){
                    reversecases.push_back(reversecase);
                    break;
                }
            }
            else j++;
        }
        return;
    }
    for(int i = start ; i < n ; i++){
        tmpcase.push_back(i);
        combine(n,r,i+1);
        tmpcase.pop_back();
    }
}
void permutate(int n , int r){
    if(tmpdice.size() == r){
        casesofdice.push_back(tmpdice);
        return;
    }
    for(int i = 0; i < n; i++){
        tmpdice.push_back(i);
        permutate(n,r);
        tmpdice.pop_back();
    }
}
void func(vector<int>& dicenum, vector<int>& sum, vector<vector<int>>& dice){
    for(int k = 0; k < casesofdice.size(); k++){
        int sumamount = 0;
        for(int j = 0 ; j < dicenum.size() ; j++){
            sumamount += dice[dicenum[j]][casesofdice[k][j]];
        }
        sum.push_back(sumamount);
    }
}
vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    int n = dice.size();
    int r = n / 2 ;
    
    combine(n,r,0);
    permutate(6, r);
    
    
    
    int wincnt = 0;
    int index = 0;
    for(int i = 0 ; i < cases.size(); i++){
        int cnt = 0;
        vector<int> suma;
        vector<int> sumb;
        func(cases[i], suma, dice);
        func(reversecases[i], sumb, dice);
        
        int idxb = 0;
        sort(suma.begin(), suma.end());
        sort(sumb.begin(),sumb.end());
        for(int j = 0 ; j < suma.size(); j++){
            while( idxb < sumb.size() && sumb[idxb] < suma[j]){
                idxb++;
            }
            cnt += idxb;
        }
        if (wincnt < cnt){
            wincnt = cnt;
            index = i;
        } 
    }
        
    for(int i = 0 ; i < r ; i++){
        answer.push_back(cases[index][i]+1);    
    }
    return answer;
}