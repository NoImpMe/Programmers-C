#include <string>
#include <vector>
#include <climits>
using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for(auto in : info){
        int a = in[0];
        int b = in[1];
        vector<int> tmp_dp(n, INT_MAX);
        for(int i = 0 ; i < n ; i++){
            if(dp[i] == INT_MAX) continue;
            //a 뽑앗다
            if( i+a < n) tmp_dp[i+a] = min(tmp_dp[i+a], dp[i]);
            
            //b 뽑았다
            if(dp[i]+b < m) tmp_dp[i] = min(tmp_dp[i], dp[i]+b);
        }
        dp = tmp_dp;
    }
    for(int i = 0 ; i < n ; i++){
        if(dp[i] < m){
            return i;
        }
    }
    return -1;
}