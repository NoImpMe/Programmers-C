#include <string>
#include <vector>
#include <map>
#include<algorithm>
#include <cmath>
using namespace std;
//기본 시간, 기본요금, 몇분당?, 단위요금
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int btime = fees[0];
    int bfee = fees[1];
    int pertime = fees[2];
    int perfee = fees[3];
    vector<string> carnum;
    vector<int> cartime;
    map<string, int> intime;
    for(auto rec : records){
        auto carname =rec.substr(6,4);
        if(rec[11] == 'I'){
            int h = stoi(rec.substr(0,2));
            int m = stoi(rec.substr(3,2));
            int time = h*60 + m;
            carnum.push_back(carname);
            cartime.push_back(time);
        }
        else{
            int idx = find(carnum.begin(), carnum.end(),carname) - carnum.begin();
            int h = stoi(rec.substr(0,2));
            int m = stoi(rec.substr(3,2));
            int time = h*60 + m;
            
            if(intime.find(carname) == intime.end()){
                intime[carname] = time - cartime[idx];
            }
            else intime[carname] += time - cartime[idx];
            carnum.erase(carnum.begin() + idx);
            cartime.erase(cartime.begin() + idx);
        }
    }
    while(!carnum.empty()){
        int h = 23;
        int m = 59;
        int time = h*60 + m;
        if(intime.find(carnum[0]) == intime.end()){
                intime[carnum[0]] = time - cartime[0];
            }
        else intime[carnum[0]] += time - cartime[0];
        carnum.erase(carnum.begin());
        cartime.erase(cartime.begin());
    }
    for( auto car : intime){
        int fee = 0;
        if(car.second < btime) fee = bfee;
        else fee = bfee + ceil((car.second - btime) / (double)pertime) * perfee;
        answer.push_back(fee);
    }
    
    //추가문ㅓㅏㅣㅓㅣ
    return answer;
}