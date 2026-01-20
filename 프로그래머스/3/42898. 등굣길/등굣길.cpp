#include <string>
#include <vector>

using namespace std;
int solution(int m, int n, vector<vector<int>> puddles) {
    long answer = 0;
    vector<vector<int>> dp(n,vector<int>(m,0));
    dp[0][0] = 1;
    for(auto pud : puddles){
        dp[pud[1]-1][pud[0]-1] = -1;
    }
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j++){
            if( i ==0 && j == 0) continue;
            if( dp[i][j] == -1) continue;
            int count = 0;
            if( i-1 >= 0 && dp[i-1][j] != -1 )
            {
                count += dp[i-1][j];
            }
            if( j-1 >= 0 && dp[i][j-1] != -1){
                count += dp[i][j-1];
            }
            dp[i][j] = count % 1000000007;
        }
    }
    answer = dp[n-1][m-1];
    return answer;
}

