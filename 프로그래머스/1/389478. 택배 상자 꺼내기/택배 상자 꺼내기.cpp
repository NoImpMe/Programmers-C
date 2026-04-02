#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    if( w == 1){
        return n - num+1;
    }
    int h = n / w + 1;
    vector<vector<int>> v(h , vector<int>(w, 0));
    int idx = 1;
    int r, c;
    int i = 0;
    while( idx <= n ){
        if( i % 2 == 0){
            for( int j = 0 ; j < w; j++){
                if(idx == num){
                    r = i;
                    c = j;
                }
                v[i][j] = idx;
                idx += 1;
                if(idx > n) break;
            }    
            
        }
        else{
            for(int j = w-1 ; j >= 0 ; j--){
                if(idx == num){
                    r = i;
                    c = j; 
                }
                v[i][j] = idx;
                idx += 1;
                if(idx > n) break;
            }
        }
        i += 1;
    }
    for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < w; j++){
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
    while(r < h){
        if(v[r][c] > 0){
            answer++;
        }
        r+=1;
    }
    return answer;
}