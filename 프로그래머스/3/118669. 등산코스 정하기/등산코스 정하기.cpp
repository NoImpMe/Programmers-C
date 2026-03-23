#include <string>
#include <vector>
#include <queue>
using namespace std;
const int INT_MAX = 1e9;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    vector<vector<pair<int,int>>> graph(n+1);
    vector<bool> isgate (n+1, false);
    vector<bool> issummit(n+1, false);
    for(auto path : paths){
        int u = path[0];
        int v = path[1];
        int w = path[2];
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    for(int i = 0 ; i < gates.size(); i++){
        isgate[gates[i]] = true;
    }
    for(int i = 0 ; i < summits.size(); i++){
        issummit[summits[i]] = true;
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    vector<int>dist (n+1,INT_MAX);
    for( int g : gates){
        dist[g] = 0;
        pq.push({0,g});
        int gatecnt = 0;

        while(!pq.empty()){
            auto [cost, u] = pq.top();
            pq.pop();

            if( cost > dist[u]) continue;
            if(issummit[u]) continue;

            if(isgate[u]){
                if(gatecnt > 0){
                    continue;
                }
                gatecnt++;
            } 
            for( auto [v,w] : graph[u]){
                int newcost = max(cost, w);
                if( newcost < dist[v]){
                    dist[v] = newcost;
                    pq.push({newcost,v});
                }
            }
        }
    }
    
    pair<int, int> res = {INT_MAX, INT_MAX};
    for(int i = 0 ;i < summits.size(); i++){
        if(res.second > dist[summits[i]]){
            res.first = summits[i];
            res.second = dist[summits[i]];
        }
        else if(res.second == dist[summits[i]] && res.first > summits[i]){
            res.first = summits[i];
        }
    }
    
    answer.push_back(res.first);
    answer.push_back(res.second);
    return answer;
}