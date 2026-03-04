#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> dfs(int num,const vector<vector<int>>& graph, vector<bool> &isvisited){
    vector<int> cnt = {0,0};
    
    while(!isvisited[num]){
        isvisited[num] = true;
        cnt[0]++;
        if(graph[num].size() == 1){
            num = graph[num][0];
            cnt[1]++;
        }
        else if( graph[num].size() == 2){
            cnt[1] += 2;
            vector<int> tmp = dfs(graph[num][1], graph, isvisited);
            cnt[0] += tmp[0];
            cnt[1] += tmp[1];
            num = graph[num][0];
        }
    }
    return cnt;
}
vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4,0);
    vector<vector<int>> graphout(1000001);
    vector<vector<int>> graphin(1000001);
    int maxnum = 0;
    for(int i = 0 ; i < edges.size(); i++){
        if(edges[i][0] > maxnum) maxnum = edges[i][0];
        if(edges[i][1] > maxnum) maxnum = edges[i][1];
        graphout[edges[i][0]].push_back(edges[i][1]);
        graphin[edges[i][1]].push_back(edges[i][0]);
    }
    graphout.resize(maxnum+1);
    graphin.resize(maxnum+1);
    graphout.shrink_to_fit();
    graphin.shrink_to_fit();
    vector<bool> isvisited (maxnum+1, false);
    for(int i = 1 ; i < graphout.size() ; i++){
        if(graphout[i].size() > 1 && graphin[i].size() == 0){
            answer[0] = i;
            break;
        }
    }
    isvisited[answer[0]] = true;
    for(int i = 1 ; i < graphout.size(); i++){
        if( i == answer[0] || isvisited[i]) continue;
        if(graphout[i].size() == 0) {
            if(graphin[i].size() == 1 && graphin[i][0] == answer[0]) answer[2] += 1;
            continue;
        }
        vector<int> tmp = dfs(i, graphout, isvisited);
        if(tmp[1] == 0 && tmp[0] == 0){
            continue;
        }
        int chk = tmp[1] - tmp[0];
        if(chk == 0) answer[1] += 1;
        else if ( chk == -1) {
            int left = i;
            while(graphin[left].size() > 0){
                if(graphin[left][0] == answer[0]){
                    if(graphin[left].size() > 1){
                        isvisited[graphin[left][1]] = true;
                        left = graphin[left][1];    
                    }
                    else break;
                }
                else {
                    isvisited[graphin[left][0]] = true;
                    left = graphin[left][0];
                }
            }
            
            answer[2] += 1;
        }
        else if(chk == 1) answer[3] += 1;
    }
    return answer;
}