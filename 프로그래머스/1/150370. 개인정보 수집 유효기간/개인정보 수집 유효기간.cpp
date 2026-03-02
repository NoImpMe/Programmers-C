#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> termmap;
    int todayy = stoi(today.substr(0,4));
    int todaym = stoi(today.substr(5,2));
    int todayd = stoi(today.substr(8,2));
    for(int i = 0 ; i < terms.size(); i++){
        termmap[terms[i][0]] = stoi(terms[i].substr(2));
    }
    for(int i = 0 ; i < privacies.size(); i++){
        int term = termmap[privacies[i][11]];
        int year = stoi(privacies[i].substr(0,4));
        int month = stoi(privacies[i].substr(5,2));
        int day = stoi(privacies[i].substr(8,2)) - 1;
        
        month += term;
        if( month > 12){
            year += month/12;
            month %= 12;
        }
        if( day <= 0) {
            day = 28;
            month -= 1;
        }
        if(month <= 0){
            month = 12;
            year -= 1;
        }
        
        if(todayy > year){
            answer.push_back(i+1);
        }
        else if ( todayy == year){
            if(todaym > month){
                answer.push_back(i+1);
            }
            else if (todaym == month){
                if(todayd > day){
                    answer.push_back(i+1);
                }
            }
            else continue;
        }
        else continue;
    }
    return answer;
    
}