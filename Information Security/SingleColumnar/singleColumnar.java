import java.util.*;

class singleColumnar{
    public static void main(String args[]){
        String text = "BUY SOME MILK AND EGGS";
        String key = "MONEY";
        String alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int count = 0;
        HashMap<Character, Integer> temp = new HashMap<>();
        for(int i = 0; i < alpha.length(); i++ ){
            if(alpha.charAt(i) == key.charAt(i)) {
                temp.put(key.charAt(i), count );
                count++;
            }
        }

        HashMap<Character, StringBuilder> map = new HashMap<>();
        for(int i = 0; i < text.length(); i++ ){
            if(i < key.length()){
                StringBuilder t = new StringBuilder();
                t.append(map.getOrDefault(key.charAt(i%key.length()), t));
                t.append(text.charAt(i));
                map.put(key.charAt(i%key.length()), t);
            }
            map.put(key.charAt(i%key.length()), map.get(key.charAt(i%key.length())).append(text.charAt(i)));
        }
        
    }
}