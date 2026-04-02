#include <string>
#include <vector>
#include <iostream>
using namespace std;
void allcase(int n, int start, vector<int>& input, vector<vector<int>>& lists){
    if(input.size() == 5){
        lists.push_back(input);
    }
    for(int i = start ; i <= n ; i++){
        if(input.size() == 5) break;
        input.push_back(i);
        allcase(n, i+1, input, lists);
        input.pop_back();
    }
}
int samenumbercnt(vector<int>& a, vector<int>& b){
    int idxa = 0;
    int idxb = 0;
    int res = 0;
    while(idxa < 5){
        if(a[idxa] == b[idxb]){
            res += 1;
            idxa += 1;
            idxb += 1;
        }
        else if(a[idxa] < b[idxb]){
            idxa += 1;
        }
        else if (a[idxa] > b[idxb]){
            idxb += 1;
        }
    }
    return res;
}
int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    
    vector<vector<int>> lists;
    vector<int> input;
    
    lists.reserve(150000);
    
    allcase(n, 1, input, lists);
    
    for(int i = 0 ; i < q.size(); i++){
        vector<vector<int>> cand;
        cand.reserve(150000);
        for( auto list : lists){
            int tmp = samenumbercnt(q[i], list);
            if(tmp == ans[i]){
                cand.push_back(list);
            }
        }
        lists.swap(cand);
    }
    return lists.size();
}