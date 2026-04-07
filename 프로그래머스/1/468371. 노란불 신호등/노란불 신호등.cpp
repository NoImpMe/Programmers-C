#include <string>
#include <vector>
#include <numeric>
using namespace std;
int get_lcm(int a, int b){
    if( a == 0 || b == 0) return 0;
    return a * b / gcd(a,b);
}
int solution(vector<vector<int>> signals) {
    int answer = 0;
    vector<int> cycle;
    int n = signals.size();
    int max = 1;
    for(int i = 0 ; i < n ; i++){
        cycle.push_back(signals[i][0]+signals[i][1]+signals[i][2]);
        max = get_lcm(max , cycle[i]);
    }
    
    for(int i = 1 ; i <= max; i++){
        bool yellow = true;
        for(int j = 0 ; j < n ; j++){
            int g = signals[j][0];
            int y = signals[j][1];
            int cur = (i - 1) % cycle[j];
            if( cur >= g+y || cur < g ){
                yellow = false;
                break;
            }
        }
        if( yellow ) return i;
    }
    return -1;
}