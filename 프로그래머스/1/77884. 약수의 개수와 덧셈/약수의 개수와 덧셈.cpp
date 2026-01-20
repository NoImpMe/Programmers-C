#include <string>
#include <vector>

using namespace std;
bool oddcheck(int num){
    if( num == 1 ) return false;
    int i = 2;
    for(int i = 2 ; i <= num/2 ; i++){
        if( num % i == 0 ){
            if( (num / i) == i) return false;
        }
    }
    return true;
}
int solution(int left, int right) {
    int answer = 0;
    for(int i = left; i <= right ; i++){
        if( oddcheck(i) ){
            answer += i;
        }
        else answer += i * -1;
    }
    return answer;
}