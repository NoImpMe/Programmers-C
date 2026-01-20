//22012144 김민우
import java.util.HashSet;
import java.util.Arrays;
import java.util.Iterator;
class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        int n = phone_book.length;
        HashSet hs = new HashSet<String>(Arrays.asList(phone_book));
        Iterator<String>it = hs.iterator();
        while(it.hasNext()){
            var tmp = it.next();
            for(int i = 1 ; i < tmp.length() ; i++){
                if(hs.contains(tmp.substring(0,i))){
                    return false;
                }      
            }
        }
        
    
        
        return answer;
    }
}