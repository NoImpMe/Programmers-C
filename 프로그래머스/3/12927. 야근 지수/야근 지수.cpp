#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    long long total = 0;
    for (int work : works){
        total += work;
    }
    if (total <= n) return 0;
    
    sort(works.begin(), works.end(), greater<int>());
    int max_work = works[0];
    int left = 0;
    int right = max_work;
    while( left < right)
    {
        int mid = (left + right) / 2;
        long long sum = 0;
        for(int work : works){
            if(work > mid){
                sum += (work - mid);
            }
        }
        if(sum < n){
            right = mid;
        }
        else if (sum >= n){
            left = mid + 1;
        }
    }
    for(int& work : works){
        if(work > left){
            n -= (work - left);
            work = left;
        }
    }
    while(n > 0){
        auto it = max_element(works.begin(), works.end());
        if(*it == 0) break;
        (*it) -= 1;
        n -= 1;
    }
    for(int i : works){
        answer += i*i;
    }
    return answer;
}