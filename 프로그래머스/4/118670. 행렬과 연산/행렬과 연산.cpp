#include <string>
#include <vector>
#include <deque>
using namespace std;


vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    
    int N = rc.size();
    int M = rc[0].size();
    deque<int> left_col;
    deque<int> right_col;
    deque<deque<int>> rows;
    
    for(int i = 0 ; i < N ; i++){
        left_col.push_back(rc[i][0]);
        right_col.push_back(rc[i][M-1]);
        deque<int> mid_row;
        for(int j = 1 ; j < M-1 ; j++){
            mid_row.push_back(rc[i][j]);
        }
        rows.push_back(mid_row);
    }
    for(string op : operations){
        if(op[0] == 'S'){
            left_col.push_front(left_col.back());
            left_col.pop_back();
            
            right_col.push_front(right_col.back());
            right_col.pop_back();
            
            rows.push_front(move(rows.back()));
            rows.pop_back();
        }
        else{
            rows.front().push_front(left_col.front());
            left_col.pop_front();
            
            right_col.push_front(rows.front().back());
            rows.front().pop_back();
            
            rows.back().push_back(right_col.back());
            right_col.pop_back();
            
            left_col.push_back(rows.back().front());
            rows.back().pop_front();
        }
    }
    
    vector<vector<int>> answer(N, vector<int>(M));
    
    for(int i = 0 ; i < N; i++){
        answer[i][0] = left_col.front();
        answer[i][M-1] = right_col.front();
        left_col.pop_front();
        right_col.pop_front();
    }
    for(int i = 0 ; i < N ; i++){
        for(int j = 1 ; j < M-1 ; j++){
            answer[i][j] = rows.front().front();
            rows.front().pop_front();
        }
        rows.pop_front();
    }
    return answer;
}