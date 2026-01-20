#include <string>
#include <vector>
using namespace std;

int solution(vector<int> a) {
    int answer = 2;
    vector<int> minlv(a.size(),0);
    vector<int> minrv(a.size(),0);
    int minl = 1000000001;
    int minr = 1000000001;
    int idx = a.size()-1;
    for(int i = 0; i < a.size(); i++){
        if(minl > a[i]){
            minl = a[i];
        }
        if(minr > a[idx]){
            minr = a[idx];
        }
        minlv[i] = minl;
        minrv[idx--] = minr;
    }
    for(int i = 1; i < a.size()-1; i++){
        if( a[i] < minlv[i-1] || a[i] < minrv[i+1]){
            answer++;
        }
    }
    return answer;
}