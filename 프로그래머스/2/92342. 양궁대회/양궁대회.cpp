#include <string>
#include <vector>


using namespace std;

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    int maxdiff = 0;
    for(int i = 0 ; i < (1 << 11); i++){
        int use = 0;
        int ryanpoint = 0;
        int apeachpoint = 0;
        int ryan[11] = {0,};
        
        for(int j = 0 ; j < 11 ; j++){
            int point = 10 - j;
            if( i & (1 << j)){
                ryan[j] = info[j] + 1;
                use += ryan[j];
                ryanpoint += point;
            }
            else {
                if(info[j] > 0) apeachpoint += point;
            }
        }
        if( use > n) continue;
        if ( ryanpoint <= apeachpoint ) continue;
        
        ryan[10] += n - use;
        
        int diff = ryanpoint - apeachpoint;
        if(maxdiff <= diff){
            if(maxdiff == diff){
                for(int k = 10 ; k >= 0 ; k--){
                    if(ryan[k] < answer[k]) break;
                    else if(ryan[k] > answer[k]) answer.assign(ryan,ryan+11);
                }
            }
            else {
                maxdiff = diff;
                answer.assign(ryan, ryan+11);
            }
        } 
        
    }
    if(answer.size() == 0){
        answer.push_back(-1);
    }
    return answer;
}