#include <string>
#include <vector>
#include <iostream>
using namespace std;


vector<int> solution(int n) {
    
    int lastnum = 0;
    
    for(int i = 1 ; i <= n ; i++){
        lastnum += i;
    }
    vector<int> answer(lastnum, 0);
    
    int dir[3] = {0, 1, 2}; //down, right, up
    int direction = 0;
    int index = 0;
    int cnt = 0;
    
    for(int i = 1 ; i <= lastnum ; i++){
        answer[index] = i;
        switch(dir[direction]){
            case 0:
                cnt++;
                index += cnt;
                
                if(index >= lastnum || answer[index] != 0){
                    direction = (direction + 1) % 3;
                    index -= cnt;
                    index++;
                }
                break;
            case 1:
                index++;
                if(index >= lastnum || answer[index] != 0){
                    direction = (direction + 1) % 3;
                    index-= cnt;
                    index--;
                }
                break;
            case 2:
                cnt--;
                index -= cnt;
                if(index < 0 || answer[index] != 0){
                    direction = (direction + 1) % 3;
                    index += cnt;
                    index += cnt;
                }
                break;
        }
    }
    return answer;
}