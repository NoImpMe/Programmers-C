#include <string>
#include <vector>
#include <numeric>
using namespace std;

long long dfs(int node, int parent, vector<int>& a, vector<vector<int>>& edges, long long& ans){
    long long sum = a[node];
    
    for( int child : edges[node]){
        if (child == parent) continue;
        long long childSum = dfs(child, node, a , edges, ans);
        ans += abs(childSum);
        sum += childSum;
    }
    return sum;
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = 0;
    double mean = accumulate(a.begin(), a.end(),0);
    if(mean != 0){
        return -1;
    }
    vector<vector<int>> adj(a.size());
    for( auto& e : edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    dfs(0 , -1 , a, adj, answer);
    return answer;
}