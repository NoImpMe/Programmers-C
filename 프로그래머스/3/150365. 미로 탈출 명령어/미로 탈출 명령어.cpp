#include <string>
#include <vector>

using namespace std;
//lrud > d l r u
string solution(int n, int m, int startx, int starty, int finishx, int finishy, int k) {
    string answer = "";
    int dist = abs(startx - finishx) + abs(starty - finishy);
    if(dist > k || (k - dist) % 2 != 0) return "impossible";
    for( ; k > 0; k--){ 
        if(startx < finishx){
            startx += 1;
            answer.push_back('d');
            dist -= 1;
        }
        else if(dist < k && startx < n){
            startx += 1;
            answer.push_back('d');
            dist += 1;
        }
        else if(starty > finishy){
            starty -= 1;
            answer.push_back('l');
            dist -= 1;
        }
        else if(dist < k && starty > 1){
            starty -= 1;
            answer.push_back('l');
            dist += 1;
        }
        else if(starty < finishy){
            starty += 1;
            answer.push_back('r');
            dist -= 1;
        }
        else if(dist < k && starty < m){
            starty += 1;
            answer.push_back('r');
            dist += 1;
        }
        else if(startx > finishx){
            startx -= 1;
            answer.push_back('u');
            dist -= 1;
        }
        else if(dist < k && startx > 1){
            startx -= 1;
            answer.push_back('u');
            dist += 1;
        }
        
    }
    if(startx == finishx && starty == finishy ){
       return answer; 
    }
    else return "impossible";
}