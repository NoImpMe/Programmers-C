#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    int num = 0;
    
    while(num < babbling.size())
    {
        int len = babbling[num].length();
        if(len == 1 || len == 9 || len > 10){
            num++;
            continue;
        }
        for(int start = 0 ; start < len ;)
        {
            if(babbling[num][start] == 'y' || babbling[num][start] == 'm'){
                if(start+2 > len) {
                    break;
                }
                string tmp = babbling[num].substr(start, 2);  
                if(tmp == "ye" || tmp == "ma"){
                    start += 2;
                    if(start == len) answer++;
                }
                else break;
            }
            else if(babbling[num][start] == 'a' || babbling[num][start] == 'w'){
                if(start+3 > len){
                    break;
                }
                string tmp = babbling[num].substr(start, 3);  
                if(tmp == "aya" || tmp == "woo"){
                    start += 3;
                    if(start == len) answer++;
                }
                else break;
            }
            else {
                break;
            }
        }
        num++;
    }
    return answer;
}