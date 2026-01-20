//22012144 김민우
class Solution {
    public String solution(String number, int k) {
        int index = 0;
        int n = number.length();
        StringBuilder answer = new StringBuilder();
        StringBuilder cpnumber = new StringBuilder();
        for(int i = 0 ; i < n ; i++){
            cpnumber.append(number.charAt(i));
        }
        int answerlen = n-k;
        
        for(int i = 0 ; i < answerlen; i++){
            char max = '0';
            int leftlen = answerlen - answer.length();
            for(int j = index ; j <= n-leftlen; j++){
                if(cpnumber.charAt(j) =='9' && n-j >= leftlen){
                    max = '9';
                    index = j+1;
                    break;
                }
                else if(cpnumber.charAt(j) > max && n-j >= leftlen){
                    max = cpnumber.charAt(j);
                    index = j+1;
                }
            }
            answer.append(max);
            
        }
        
        return answer.toString();
    }
}