#include <string>
#include <vector>
using namespace std;

bool move_plus(int& min, int& max,  int distance, int bound){
    if(max + distance < bound){
        min += (min == 0) ? 0 : distance;
        max += distance;
    }
    else if (min + distance < bound){
        min += (min == 0) ? 0 : distance;
        max = bound -1;
    }
    else if (min == 0){
        max = bound -1;
    }
    else{
        return false;
    }
    return true;
}

bool move_minus(int& min, int& max, int distance, int bound){
    if( min - distance >= 0){
        min -= distance;
        max -= (max == bound -1) ? 0 : distance; 
    }
    else if ( max - distance >= 0){
        min = 0;
        max -= (max == bound -1) ? 0 : distance;
    }
    else if (max == bound -1){
        min = 0;
    }
    else return false;
    return true;
}

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    long long answer = 0;
    int minx = x;
    int maxx = x;
    int miny = y;
    int maxy = y;
    for( auto it = queries.rbegin() ; it < queries.rend() ; ++it){
        int dir = (*it)[0];
        int distance = (*it)[1];
        
        switch(dir){
            case 0:
                if(!move_plus(miny, maxy, distance, m)){
                    return 0;
                }
                break;
            case 1:
                if(!move_minus(miny, maxy, distance, m)){
                    return 0;
                }
                break;
            case 2:
                if(!move_plus(minx, maxx, distance, n)){
                    return 0;
                }
                break;
            case 3:
                if(!move_minus(minx, maxx, distance, n)){
                    return 0;
                }
                break;
        }
    }
    answer = (long long) (maxx - minx + 1) * (maxy - miny + 1);
    return answer;
}