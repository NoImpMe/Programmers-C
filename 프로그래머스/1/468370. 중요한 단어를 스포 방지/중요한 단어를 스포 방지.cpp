#include <string>
#include <vector>
#include <sstream>
#include <unordered_set>
using namespace std;
struct Word{
    string text;
    int start;
    int end;
    bool spoiled;
};
int solution(string message, vector<vector<int>> spoiler_ranges) {
    int answer = 0;
    istringstream iss(message);
    string tmp;
    vector<Word> words;
    unordered_set<string> unhided;
    int idx = 0;
    while(iss >> tmp){
        int pos = message.find(tmp, idx);
        words.push_back({tmp, pos, pos+(int)tmp.size()-1, false});
        idx = pos + (int)tmp.size() - 1;
    }
    for(auto& word : words){
        for(auto s : spoiler_ranges){
            if(max(word.start,s[0]) <= min(word.end, s[1])){
                word.spoiled = true;
            }
        }
        if(!word.spoiled){
            unhided.insert(word.text);        
        }
    }
    for(auto word : words){
        if(word.spoiled){
            if(unhided.find(word.text) == unhided.end()){
                answer++;
            }
            unhided.insert(word.text);
        }
    }
    return answer;
}