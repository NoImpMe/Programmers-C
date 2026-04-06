#include <string>
#include <vector>
#include <unordered_set>
#include <sstream>
using namespace std;
struct word{
    string text;
    int start;
    int end;
    bool hided;
};
int solution(string message, vector<vector<int>> spoiler_ranges) {
    int answer = 0;
    unordered_set<string> unhided;
    vector<word> words;
    istringstream iss(message);
    int idx = 0;
    string tmp;
    while(iss >> tmp){
        int pos = message.find(tmp, idx);
        words.push_back({tmp, pos, pos+(int)tmp.size()-1, false});
        idx = pos + (int)tmp.size();
    }
    int n = spoiler_ranges.size();
    for(auto& wd : words){
        for(auto range : spoiler_ranges){
            if(max(wd.start,range[0]) <= min(wd.end, range[1])){
                wd.hided = true;
            }
        }
        if(!wd.hided) unhided.insert(wd.text);
    }
    unordered_set<string> discovered;
    for(auto wd : words){
        if(wd.hided){
            if((unhided.find(wd.text) == unhided.end()) && (discovered.find(wd.text) == discovered.end())){
                answer += 1;
            }
            discovered.insert(wd.text);
        }
    }
    
    return answer;
}