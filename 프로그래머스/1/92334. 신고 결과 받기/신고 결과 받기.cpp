#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    
    int n = id_list.size();
    vector<int> answer(n,0);
    vector<vector<bool>> reportlist(n , vector<bool>(n,false));
    vector<int> reportedcnt(n,0);
    
    string token;
    for( string r : report){
        vector<string> tokens;
        istringstream iss(r);
        while( iss >> token){
            tokens.push_back(token);
        }
        int reporter = find(id_list.begin(), id_list.end(), tokens[0]) - id_list.begin();
        int reported = find(id_list.begin(), id_list.end(), tokens[1]) - id_list.begin();
        if(!reportlist[reporter][reported]){
            reportlist[reporter][reported] = true;
            reportedcnt[reported]++;    
        }
    }
    for(int i = 0 ; i < n; i++){
        if(reportedcnt[i] >= k){
            for(int j = 0 ; j < n ; j++){
                if(reportlist[j][i]) answer[j]++;
            }
        }
    }
    return answer;
}