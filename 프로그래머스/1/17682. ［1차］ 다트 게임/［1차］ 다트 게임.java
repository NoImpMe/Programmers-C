//22012144 김민우
import java.util.ArrayList;
public class Solution {
    public int solution(String dartResult){
        int answer = 0;
        ArrayList <Double> res = new ArrayList<Double>();
        int[] option = {1,1,1};
        int cnt = 0;
        for(int i = 0 ; i < dartResult.length() ; i++){
            if(String.valueOf(dartResult.charAt(i)).matches("[0-9]")){
                if(dartResult.charAt(i) == '1'){
                    if(dartResult.charAt(i+1) == '0'){
                        res.add(10.0);
                        i++;
                    }
                    else{
                        res.add(Double.parseDouble(String.valueOf(dartResult.charAt(i))));
                    }
                }
                else{
                    res.add(Double.parseDouble(String.valueOf(dartResult.charAt(i))));
                }

            }
            else if(String.valueOf(dartResult.charAt(i)).matches("[S|D|T]")){
                switch(String.valueOf(dartResult.charAt(i))){
                    case "S":{
                        res.set(cnt,Math.pow(res.get(cnt++), 1));
                        break;
                    }
                    case "D":{
                        res.set(cnt,Math.pow(res.get(cnt++), 2));
                        break;
                    }
                    case "T":{
                        res.set(cnt,Math.pow(res.get(cnt++), 3));
                        }
                }
            }
            else if(String.valueOf(dartResult.charAt(i)).matches("[*|#]")){
                switch(String.valueOf(dartResult.charAt(i))){
                    case "*": {
                        if (i != 2) {option[i / 6] *= 2;}
                        option[i / 3] *= 2;
                        break;
                    }
                    case "#": {
                        option[i / 3] *= -1;
                    }
                }
            }
            else{
                System.out.println("입력 값 오류 종료합니다.");
                return 0;
            }
        }
        answer = (int)(res.get(0)*option[0] + res.get(1)*option[1]+ res.get(2)*option[2]);
        return answer;
    }
}