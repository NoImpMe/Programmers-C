#include <string>
#include <vector>
#include <climits>
using namespace std;
vector<vector<int>> boards(5, vector<int>(5,0));

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
pair<bool,int> dfs(int ax, int ay, int bx, int by){
    bool canmove = false;
    for(int i = 0 ; i < 4; i++){
        int nx = ax + dx[i];
        int ny = ay + dy[i];
        if( nx >= 0 && ny >=0 && nx < 5 && ny < 5 && boards[nx][ny] == 1){
            canmove = true;
            break;
        }
    }
    if(!canmove) return {false,0};
    
    bool canwin = false;
    int minwin = INT_MAX;
    int maxlose = 0;
    int prev = boards[ax][ay];
    boards[ax][ay] = 0;
    
    for( int i = 0 ; i < 4 ; i++){
        int nx = ax + dx[i];
        int ny = ay + dy[i];
        if ( nx < 0 || ny < 0 || nx > 4 || ny > 4 || boards[nx][ny] == 0) continue;
        if(ax == bx && ay == by) {
            canwin = true;
            minwin = min(minwin, 1);
            continue;
        }
        auto [opwin, opdist]  = dfs(bx, by, nx, ny);
        if(!opwin) {
            canwin = true;
            minwin = min(minwin, opdist+1);
        }
        else{
            maxlose = max(maxlose, opdist+1);
        }
    }
    boards[ax][ay] = prev;
    if(canwin) return {canwin,minwin};
    else return {canwin,maxlose};
}
int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    for(int i = 0 ; i < 5; i++){
        for(int j = 0 ; j < 5 ; j++){
            boards[i][j] = 0;
        }
    }
    for(int i = 0 ; i < board.size(); i++){
        for(int j = 0 ; j < board[0].size() ; j++){
            boards[i][j] = board[i][j];
        }
    }
    auto [win, adist] = dfs(aloc[0], aloc[1], bloc[0], bloc[1]);
    
    return adist;
}