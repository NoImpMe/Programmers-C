#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<int> bfs(int start, vector<vector<int>> adj){
    vector<int> dist(adj.size(), -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for( int next : adj[cur]){
            if(dist[next] == -1){
                dist[next] = dist[cur] +1;
                q.push(next);
            }
        }
    }
    return dist;
}
int solution(int n, vector<vector<int>> edges) {
    int answer = 0;
    vector<vector<int>> adj(n);
    for(auto& e : edges){
        int u = e[0] -1;
        int v = e[1] -1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dist0 = bfs(0, adj);
    int u = 0;
    for(int i = 1 ; i < n ; i++){
        if(dist0[i] > dist0[u] ) u = i;
    }
    vector<int> distu = bfs(u, adj);
    int v = 0;
    for(int i = 0 ; i < n ; i++){
        if(distu[i] > distu[v]) v = i;
    }
    vector<int> distv = bfs(v, adj);
    int count = 0;
    for(int i = 0 ; i < n ; i++){
        if(distu[v] == distu[i]){
            count++;
        }
    }
    if( count >= 2) return distu[v];
    count = 0;
    for(int i = 0 ; i < n ; i++){
        if(distv[i] == distu[v]){
            count++;
        }
    }
    if( count >= 2) return distu[v];
    return distu[v] - 1;
}