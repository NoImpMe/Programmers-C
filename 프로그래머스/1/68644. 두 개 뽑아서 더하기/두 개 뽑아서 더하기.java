//22012144 김민우
import java.util.HashSet;
import java.util.Arrays;
import java.util.Iterator;

class Solution {
    public int [] solution(int[] numbers) {
        int [] answer = {};
        HashSet<Integer> set = new HashSet<>();
        for(int i = 0 ; i < numbers.length ; i++){
            for (int j = i+1 ; j < numbers.length; j++){
                int res = numbers[i]+numbers[j];
                set.add(res);
            }
        }
        Iterator it = set.iterator();
        answer = new int[set.size()];
        int i = 0;
        
        while (it.hasNext()){
            answer[i++] = (int)it.next();
        }
        Arrays.sort(answer);
        return answer;
    }
}