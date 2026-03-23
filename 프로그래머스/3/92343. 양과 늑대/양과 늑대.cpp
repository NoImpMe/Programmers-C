#include <string>
#include <vector>
using namespace std;

vector<bool> nodes;
vector<vector<int>> edge;
vector<int> infos;
void bfs(int start, int sheep, int wolf, vector<vector<int>>& adj, int& answer){
    if( sheep > 0 && sheep <= wolf) return;
    if( infos[start]){
        wolf++;
    }
    else sheep++;
    answer = max(answer, sheep);
    for( auto a : adj[start]){
        nodes[a] = true;
    }
    for(int i = 0 ; i < infos.size(); i++){
        if(nodes[i]){
            nodes[i] = false;
            bfs(i, sheep, wolf, adj, answer);
            nodes[i] = true;
        }
    }
    for( auto a : adj[start]){
        nodes[a] = false;
    }
    
}
int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    infos = info;
    edge = edges;
    vector<bool> tmp(info.size(), false);
    nodes = tmp;
    vector<vector<int>> adj(info.size());
    for( auto& edge : edges){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }
    bfs(0,0,0, adj, answer);
    return answer;
}