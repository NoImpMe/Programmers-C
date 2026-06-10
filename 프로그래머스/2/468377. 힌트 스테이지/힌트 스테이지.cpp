#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<int> costpointer;
int resultfee = INT_MAX;
int laststage = 0;
void calcfee(vector<vector<int>>& cost, vector<vector<int>>& hint, int stage, int fee){
    
    fee += cost[stage][costpointer[stage]];
    if(stage == laststage){
        resultfee = min(resultfee, fee);
        return;
    }
    vector<int> originpointer = costpointer;
    fee += hint[stage][0];
    for(int i = 1 ; i < hint[stage].size(); i++){
        if(costpointer[hint[stage][i]-1] == laststage) continue;
        costpointer[hint[stage][i]-1]++;
    }
    
    calcfee(cost, hint, stage+1, fee);
    fee -= hint[stage][0];
    costpointer = originpointer;
    calcfee(cost, hint, stage+1, fee);
}

int solution(vector<vector<int>> cost, vector<vector<int>> hint) {
    
    laststage = cost.size()-1;
    
    for(int i = 0 ; i < cost.size(); i++){
        costpointer.push_back(0);    
    }
    calcfee(cost, hint, 0, 0);
    
    return resultfee;
}