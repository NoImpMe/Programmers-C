//22012144 김민우
import java.util.Arrays;
import java.util.Comparator;

class Solution {
   public int solution(int[][] routes) {
        int answer = 0;
        int cam = -30000;
        Arrays.sort(routes, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[1] - o2[1];
            }
        });
        for (int i = 0 ; i < routes.length ; i++){
            if( cam >= routes[i][0] && cam <= routes[i][1]){
                continue;
            }
            cam = routes[i][1];
            answer++;
        }
        return answer;
   }
}
