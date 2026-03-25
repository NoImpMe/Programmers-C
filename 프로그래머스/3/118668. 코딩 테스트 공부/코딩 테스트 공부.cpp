#include <string>
#include <vector>
#include <climits>
using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    int probnum = problems.size();
    int maxalp = alp;
    int maxcop = cop;
    
    for(auto p : problems){
        maxalp = max(p[0], maxalp);
        maxcop = max(p[1], maxcop);
    }
    
    vector<vector<int>> dp(maxalp+1, vector<int>(maxcop+1, INT_MAX));
    dp[alp][cop] = 0;
    
    for(int i = alp; i <= maxalp; i++){
        for(int j = cop; j <= maxcop; j++){
            if(dp[i][j] == INT_MAX) continue;
            
            if(i+1 <= maxalp){
                dp[i+1][j] = min(dp[i][j]+1 , dp[i+1][j]);
            }
            if(j+1 <= maxcop){
                dp[i][j+1] = min(dp[i][j]+1, dp[i][j+1]);
            }
            for( auto p : problems){
                if(i >= p[0] && j>= p[1]){
                    int ni = min(i+p[2], maxalp);
                    int nj = min(j+p[3], maxcop);
                    dp[ni][nj] = min(dp[i][j]+p[4], dp[ni][nj]);
                }
            }
        }
    }
    return dp[maxalp][maxcop];
}