#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int k = 0 ; k < 5 ; k++){
        int mark = 1;
        for(int i = 0 ; i < 5 ; i++){
            if(mark == 0) break;
            for( int j = 0 ; j < 5 ; j++){
                if(places[k][i][j] == 'P'){
                    if( i < 4 ){
                        if(places[k][i+1][j] == 'P') {
                             mark = 0;
                             break;
                        }
                        if(places[k][i+1][j] == 'O' ){
                            if(j < 4 && places[k][i+1][j+1] == 'P'){
                                mark = 0;
                                break;
                            }                  
                            if(i < 3 && places[k][i+2][j] == 'P'){
                                mark = 0;
                                break;
                            }
                            if( j > 0 && places[k][i+1][j-1] == 'P'){
                                mark = 0;
                                break;
                            }   
                        }
                    }
                    if( j != 4){
                        if(places[k][i][j+1] == 'P'){
                            mark = 0;
                            break;
                        }
                        if(places[k][i][j+1] == 'O' ){
                            if( i < 4 && places[k][i+1][j+1] == 'P'){
                                mark = 0;
                                break;
                            }
                            if(j < 3 && places[k][i][j+2] == 'P'){
                                mark = 0;
                                break;
                            }
                        }
                    }
                    if( j > 0){
                        if(places[k][i][j-1] == 'O'){
                            if( i < 4 && places[k][i+1][j-1] == 'P'){
                                mark = 0;
                                break;
                            }
                        }
                    }
                    
                }  
                else continue;
            }
        }
        answer.push_back(mark);
    }
    
    return answer;
}