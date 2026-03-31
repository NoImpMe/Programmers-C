#include <string>
#include <vector>
using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int curserver = 1;
    int curmax = 0;
    vector<int> time(24,0);
    for(int i = 0 ; i < players.size(); i++){
        if(time[i] > 0) curserver -= time[i];
        curmax = curserver * m;
        if(players[i] >= curmax){
            int addserver = (players[i] - curmax) / m+1;
            if(i < 24-k) time[i+k] += addserver;
            curserver += addserver;
            answer += addserver;
        }
    }
    return answer;
}