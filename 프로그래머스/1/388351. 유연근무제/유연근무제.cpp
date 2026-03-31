#include <string>
#include <vector>

using namespace std;

bool safe(int option, int arrive){
    int oh = option / 100 * 60 + option % 100;
    int ah = arrive / 100 * 60 + arrive % 100;
    if(oh - ah < -10){
        return false;
    }
    return true;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int idx = 0;
    int days;
    for( int s : schedules){
        bool sucess = true;
        days = startday;
        for(int i = 0 ; i < 7 ; i++){
            if(days < 6){
                if(!safe(s, timelogs[idx][i])) sucess = false;
            }
            days = days % 7 + 1;
        }
        if(sucess) answer += 1;
        idx += 1;
    }
    return answer;
}