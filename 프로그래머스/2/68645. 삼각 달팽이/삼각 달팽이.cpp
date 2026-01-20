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
// int cnt = 0;
//     int idxX = 0;
//     int idxY = 0;
//     int nx = n;
//     int ny = n;
//     while(cnt <= lastnum){
//         cnt++;
//         if(tmp[idxX][idxY] != 0){
//             tmp[idxX][idxY] = cnt;    
//         }
        
//         if(idxY+1 == ny && idxX+1 == nx){
//             nx--;
//         }
//         else if(idxY+1 == ny){
//             idxX--;
//             idxY--;
//             ny--;
//         }
//         else if(idxX +1 == nx){
//             idxY++;
//         }
//         else {
//             idxX++;
//         }
//     }
//     for(int i = 0 ; i < n ; i++){
//         for(int j = 0 ; j <= i ; j++){
//             answer.emplace_back(tmp[i][j]);
//         }
//     }