#include <string>
#include <vector>
#include <queue>
using namespace std;
int N;
int res = 0;
void spread(vector<bool>& infected, int pipe, vector<vector<int>>& adj){
    queue<int> q;
    for(int i = 1; i <= N ; i++){
        if(infected[i]) q.push(i);
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0 ; i <= N; i++){
            if(adj[u][i] == pipe && !infected[i]){
                infected[i] = true;
                q.push(i);
            }
        }
    }
}
void dfs(vector<bool>& infected,vector<vector<int>>adj, int k){
    int cnt = 0;
    for(int i = 1 ; i <= N ; i++) if(infected[i]) cnt++;
    res = max(res, cnt);
    if(k == 0 || cnt == N) return;
    for(int i = 1; i <= 3; i++){
        vector<bool> tmp = infected;
        spread(tmp, i, adj);
        if(tmp == infected) continue;
        dfs(tmp, adj, k-1);
    }
}
int solution(int n, int infection, vector<vector<int>> edges, int k) {
    
    N = n;
    vector<vector<int>> adj(n+1,vector<int>(n+1,-1));
    vector<bool> infected(n+1, false);
    infected[infection] = true;
    for(auto e : edges){
        int u = e[0];
        int v = e[1];
        adj[u][v] = e[2];
        adj[v][u] = e[2];
    }
    dfs(infected, adj, k);
    return res;
}