#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    int maxuser = 0;
    int payment = 0;
    
    sort(emoticons.begin(), emoticons.end());
    sort(users.begin(),users.end(), [](vector<int> &a, vector<int> &b){
        if( a[1] == b[1]){
            return a[0] < b[0];
        }
        return a[1] < b[1];
    });
    
    int n = pow(4,emoticons.size());
    
    for(int k = 0 ; k< n ; k++){
        vector<int>discount(emoticons.size());
        int tmp = k;
        for( int h = 0; h < emoticons.size(); h++){
            discount[h] = 10 + (tmp % 4 ) * 10;
            tmp /= 4;
        }
        int joiner = 0;
        int nojoinerpay = 0; 
        for(int i = 0 ; i < users.size(); i++){
            int pay = 0;
            for(int j = 0 ; j < discount.size(); j++){
                if(users[i][0] <= discount[j]){
                    pay += emoticons[j] * (100 - discount[j]) / 100;
                }
            }
            if(pay >= users[i][1]){
                joiner += 1;
            }
            else nojoinerpay += pay;
        }
        if(maxuser < joiner){
            maxuser = joiner;
            payment = nojoinerpay;
        }
        else if (maxuser == joiner){
            payment = (payment < nojoinerpay) ? nojoinerpay : payment;
        }
        
    }
    answer.push_back(maxuser);
    answer.push_back(payment);
    return answer;
}