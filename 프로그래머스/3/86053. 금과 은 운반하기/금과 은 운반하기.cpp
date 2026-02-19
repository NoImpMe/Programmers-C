#include <string>
#include <vector>
using namespace std;
long long min (long long a, long long b){
    return a < b ? a : b;
}
long long max (long long a, long long b){
    return a < b ? b : a;
}
long long pow(long long a, long long b){
    long long tmp = 1;
    for(int i = 0 ; i < b ; i++){
        tmp *= a;
    }
    return tmp;
}
bool check(long long time){
    
}
long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = -1;
    long long start = 0;
    long long end = 4 * pow(10,14);
    
    while( start < end){
        long long mid = (start + end) / 2;
        long long total = 0;
        long long totalA = 0;
        long long totalB = 0;
        bool check = false;
        for(int i = 0 ; i < g.size(); i++){
            long long cnt = mid / (2ll * t[i]);
            if(mid % (2ll * t[i]) >= t[i]){
                cnt++;
            }
            long long sum = cnt * w[i];
            total += min(sum, g[i] + s[i]);
            totalA += min(sum, g[i]);
            totalB += min(sum, s[i]);
            if(total >= a+b && totalA >= a && total >= b) check = true;
        }
        if(check){
            end = mid;
        }
        else start = mid + 1;
    }
    answer = start;
    
    return answer;
}