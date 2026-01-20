//22012144 김민우
import java.util.ArrayList;
class Solution {
    int index = 0;
    ArrayList<Integer> res = new ArrayList();
    int[] answer = {0,0};
    public int[] solution(int[][] arr) {
        int n = arr.length;
        function(arr, 0, 0, n);
        for(int i = 0 ; i < res.size(); i++){
            if(res.get(i) == 1) answer[1]++;
            else answer[0]++;
        }
        return answer;
        }
    public void function(int[][] arr, int leadx, int leady , int size){
        int tmp = 0;
        int n = size/2;
        if(size == 0) return;
        if(size == 1) {
            res.add(index++, arr[leadx][leady]);
            return;
        }
        for(int i = 0 ; i < size ; i++){
            for(int j = 0 ; j < size ; j++){
                tmp += arr[leadx+i][leady+j];
            }
        }
        if(tmp == (size * size)) { 
            res.add(index++, 1);
            return;
        }
        else if (tmp == 0){
            res.add(index++, 0);
            return;
        }
        else {
            function(arr, leadx, leady , n);
            function(arr, leadx, leady+n , n);
            function(arr, leadx+n, leady, n);
            function(arr, leadx+n, leady+n, n);
            return;
        }
        }    
    }

