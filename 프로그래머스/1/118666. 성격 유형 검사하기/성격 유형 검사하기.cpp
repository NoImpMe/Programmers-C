#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int idx = 0;
    vector<string> mbti = {"RT","CF","JM","AN"};
    vector<vector<int>> point = {
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0}
    };
    for( string s : survey){
        if(s[0] == 'R'){
            if(choices[idx] < 4){
                point[0][0] += abs(choices[idx] - 4);
            }
            else if (choices[idx] > 4){
                point[0][1] += choices[idx] - 4;
            }
        }
        if(s[0] == 'T'){
            if(choices[idx] < 4){
                point[0][1] += abs(choices[idx] - 4);
            }
            else if (choices[idx] > 4){
                point[0][0] += choices[idx] - 4;
            }
        }
        if(s[0] == 'C'){
            if(choices[idx] < 4){
                point[1][0] += abs(choices[idx] - 4);
            }
            else if (choices[idx] > 4){
                point[1][1] += choices[idx] - 4;
            }
        }
        if(s[0] == 'F'){
            if(choices[idx] < 4){
                point[1][1] += abs(choices[idx] - 4);
            }
            else if (choices[idx] > 4){
                point[1][0] += choices[idx] - 4;
            }
        }
        if(s[0] == 'J'){
            if(choices[idx] < 4){
                point[2][0] += abs(choices[idx] - 4);
            }
            else if (choices[idx] > 4){
                point[2][1] += choices[idx] - 4;
            }
        }
        if(s[0] == 'M'){
            if(choices[idx] < 4){
                printf("%d",abs(choices[idx] - 4));
                point[2][1] += abs(choices[idx] - 4);
            }
            else if (choices[idx] > 4){
                point[2][0] += choices[idx] - 4;
            }
        }
        if(s[0] == 'A'){
            if(choices[idx] < 4){
                point[3][0] += abs(choices[idx] - 4);
            }
            else if (choices[idx] > 4){
                point[3][1] += choices[idx] - 4;
            }
        }
        if(s[0] == 'N'){
            if(choices[idx] < 4){
                point[3][1] += abs(choices[idx] - 4);
            }
            else if (choices[idx] > 4){
                point[3][0] += choices[idx] - 4;
            }
        }
        idx++;
    }
    for(int i = 0; i < point.size(); i++){
        if(point[i][0] >= point[i][1]){
            answer += mbti[i][0];
        }
        else {
            answer += mbti[i][1];
        }
    }
    return answer;
}