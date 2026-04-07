#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer(2, 0);
    int n = *max_element(nodes.begin(), nodes.end());
    vector<vector<int>> adj(n+1);
    vector<int> child_cnt(n+1);
    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
        child_cnt[u]++;
        child_cnt[v]++;
    }
    vector<bool> visited(n+1 ,false);
    for(int node : nodes){
        if(visited[node]) continue;
        vector<int> component;
        vector<int> q;
        q.push_back(node);
        visited[node] = true;
        int head = 0;
        while( head < q.size()){
            int cur = q[head++];
            component.push_back(cur);
            for(int next : adj[cur]){
                if(!visited[next]){
                    visited[next] = true;
                    q.push_back(next);    
                }
            }
        }
        int fail_B = 0;
        int fail_D = 0;
        for( int u : component){
            bool B = (u % 2 == (child_cnt[u] -1) % 2);
            bool D = (u % 2 != (child_cnt[u]-1) % 2);
            if(!B) fail_B++;
            if(!D) fail_D++;
        }
        int forward = 0;
        int reverse = 0;
        for(int u : component){
            bool A = (u % 2 == child_cnt[u] % 2);
            bool B = (u % 2 == (child_cnt[u]-1)% 2);
            if( A && (fail_B - (!B ? 1 : 0) == 0)) forward++;
            bool C = (u % 2 != child_cnt[u] % 2);
            bool D = (u % 2 != (child_cnt[u]-1) % 2);
            if( C && (fail_D - (!D ? 1 : 0) == 0)) reverse++;
        }
        if( forward > 0) answer[0]++;
        if( reverse > 0) answer[1]++;
    }
    return answer;
}