#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> diff(n+1, vector<int>(m+1,0));
    for( auto act : skill ){
        int r1 = act[1];
        int c1 = act[2];
        int r2 = act[3];
        int c2 = act[4];
        int degree = act[5];
        
        if(act[0] == 1) degree = -1 * degree;
        diff[r1][c1] += degree;
        diff[r1][c2+1] -= degree;
        diff[r2+1][c1] -= degree;
        diff[r2+1][c2+1] += degree;
        
    }
    
    for( int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if( i > 0){
                diff[i][j] += diff[i-1][j];
            }
            if ( j > 0){
                diff[i][j] += diff[i][j-1];
            }
            if( i > 0 && j > 0){
                diff[i][j] -= diff[i-1][j-1];
            }
            
        }
        
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if((board[i][j] + diff[i][j]) >= 1) answer++;
        }
    }
    return answer;
}