#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int deliver = 0;
    int pickup = 0;
    
    for(int i = n-1 ; i >= 0 ; i--){
        int visitcnt = 0;
        while( deliveries[i] > deliver || pickups[i] > pickup){
            visitcnt++;
            deliver += cap;
            pickup += cap;
        }
        deliver -= deliveries[i];
        pickup -= pickups[i];
        answer += (long long)(i+1) * 2 * visitcnt;
    }
    
    return answer;
}