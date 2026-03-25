#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct Pair{
    int cost;
    pair<int, int> cards;
    Pair(int c, pair<int,int> p) : cost(c), cards(p){}
    bool operator<(Pair temp)const{
        return this->cost > temp.cost;
    }
};

int solution(int coin, vector<int> cards) {
    int answer = 1;
    priority_queue<Pair> pq;
    int n = cards.size();
    int target = n+1;
    int start = n / 3;
    unordered_map<int, bool> hand;
    unordered_map<int, int> cost;
    int i = 0;
    for(; i < start ; i++){
        hand[cards[i]] = true;
        if(hand[target-cards[i]]){
            Pair tmp(0, make_pair(cards[i], target-cards[i]));
            pq.push(tmp);
        }
    }
    for( ; i < n ; i++){
        hand[cards[i]] = true;
        cost[cards[i]] += 1;
        if(hand[target - cards[i]]){
            Pair tmp(cost[cards[i]]+cost[target-cards[i]], make_pair(cards[i], target-cards[i]));
            pq.push(tmp);
        }
        if(i % 2 == 1){
            if(!pq.empty()){
                Pair tmp = pq.top();
                pq.pop();
                coin -= tmp.cost;
                if( coin < 0) break;
                answer += 1;
            }
            else break;
        }
    }
    
    
    return answer;
}