#include <string>
#include <vector>
#include <sstream>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int n = friends.size();
    
    vector<vector<int>> amount(n , vector<int>(n,0));
    vector<int> giftpoint(n,0);
    
    for( string s : gifts){
        vector<string> tokens;
        istringstream iss(s);
        string token;
        while(iss >> token){
            tokens.push_back(token);
        }
        int i = 0;
        int j = 0;
        for(; i < n ; i++){
            if(tokens[0] == friends[i]){
                break;
            }
        }
        for(; j < n ; j++){
            if(tokens[1] == friends[j]){
                break;
            }
        }
        amount[i][j]++;
        giftpoint[i]++;
        giftpoint[j]--;
    }
    for(int i = 0; i< n ; i++){
        int cnt = 0;
        for(int j = 0 ; j < n ; j++){
            if(i == j) continue;
            if(amount[i][j] >= 0){
                if(amount[j][i] < amount[i][j]){
                    cnt++;
                }
                else if(amount[j][i] == amount[i][j]){
                    if(giftpoint[i] > giftpoint[j]){
                        cnt++;
                    }
                }
            }
            if(cnt > answer) answer = cnt;
        }
    }
    return answer;
}