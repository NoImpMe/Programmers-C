#include <string>
#include <vector>
#include <numeric>
using namespace std;

int get_lcm(int a, int b){
    if(a == 0 || b == 0) return 0;
    return (a * b) / gcd(a,b);
}

int solution(vector<vector<int>> signals) {
    int answer = 0;
    int n = signals.size();
    int max_lcm = 1;
    vector<int> cycle(n);
   for(int i = 0 ; i< n ; i++){
       cycle[i] = signals[i][0] + signals[i][1] + signals[i][2];
       max_lcm = get_lcm(cycle[i], max_lcm);
   }
    for(int i = 1 ; i <= max_lcm ; i++){
        bool yellow = true;
        for(int j = 0 ; j < n ; j++){
            int g = signals[j][0];
            int y = signals[j][1];
            int cy = cycle[j];
            int cur = (i - 1) % cy;
            if( !(cur >= g && cur < g+y)){
                yellow = false;
                break;
            }
        }
        if(yellow){
            return i;
        }
    }
    return -1;
}