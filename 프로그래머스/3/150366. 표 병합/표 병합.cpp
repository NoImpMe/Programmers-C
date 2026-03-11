#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

pair<int, int> parent[50][50];

vector<vector<string>> db(50,vector<string>(50,"EMPTY"));

pair<int, int> find(int r, int c){
    if(parent[r][c].first == r && parent[r][c].second == c){
        return {r,c};
    }
    auto [pr, pc] = find(parent[r][c].first, parent[r][c].second);
    parent[r][c] = {pr, pc};
    return {pr, pc};
}
void mergecell(int r1, int c1, int r2, int c2, string s){
    vector<pair<int, int>> member;
    for(int i = 0 ; i < 50; i++){
        for(int j = 0 ; j < 50; j++){
            if(find(i,j) == make_pair(r2,c2)){
                member.push_back({i,j});
            }
        }
    }
    for( auto [pr, pc] : member){
        parent[pr][pc] = {r1,c1};
        db[pr][pc] = s;
    }
}
void unmerge(int r, int c){
    string s = db[r][c];
    vector<pair<int,int>> member;
    auto [pr, pc] = find(r,c);
    
    for(int i = 0 ; i < 50; i++){
        for(int j = 0 ; j < 50; j++){
            if(find(i,j) == make_pair(pr,pc)){
                member.push_back({i,j});
            }
        }
    }
    for( auto [pr,pc] : member){
        parent[pr][pc] = {pr,pc};
        db[pr][pc] = "EMPTY";
    }
    db[r][c] = s;
}
void update(int r, int c, string s){
    auto[pr, pc] = find(r,c);
    
    for(int i = 0 ; i < 50; i++){
        for(int j = 0 ; j < 50; j++){
            if(find(i,j) == make_pair(pr,pc)){
                db[i][j] = s;
            }
        }
    }
}
vector<string> solution(vector<string> commands) {
    vector<string> answer;
    for(int i = 0 ; i < 50; i++){
        for(int j = 0 ; j < 50 ; j++){
            parent[i][j] = {i,j};
        }
    }
    for( auto c : commands){
        vector<string> tokens;
        istringstream iss(c);
        string token;
        while(iss >> token){
            tokens.push_back(token);
        }
        if(tokens[0] == "UPDATE"){
            if(tokens.size() == 4){ // r,c value
                int r = stoi(tokens[1]) -1;
                int c = stoi(tokens[2]) -1;
                update(r,c,tokens[3]);
            }
            else{ // val1 val2
                for( auto& row : db){
                    replace(row.begin(), row.end(), tokens[1], tokens[2]);
                }
            }
        }
        else if(tokens[0] == "MERGE"){
            
            int r1 = stoi(tokens[1])-1;
            int c1 = stoi(tokens[2])-1;
            int r2 = stoi(tokens[3])-1;
            int c2 = stoi(tokens[4])-1;
            
            string s;
                        
            if(db[r1][c1] != "EMPTY") {
                s = db[r1][c1];
                auto [pr, pc] = find(r1,c1);
                auto [pr2, pc2] = find(r2,c2);
                if( pr == pr2 && pc == pc2) continue;
                mergecell(pr,pc, pr2, pc2, s);    
            }
            else {
                s = db[r2][c2];
                auto [pr, pc] = find(r1,c1);
                auto [pr2, pc2] = find(r2,c2);
                if( pr == pr2 && pc == pc2) continue;
                mergecell(pr2,pc2, pr, pc, s);
            }
            
            
        }
        else if(tokens[0] == "UNMERGE"){
            int r = stoi(tokens[1])-1;
            int c = stoi(tokens[2])-1;
            unmerge(r,c);    
            
        }
        else{
            answer.push_back(db[stoi(tokens[1])-1][stoi(tokens[2])-1]);
        }
    }
    return answer;
}