package q4;

/**
 * Created by ramakantagrawal on 11/02/17.
 */

// Assumption: max n = 100

import java.util.HashMap;
import java.util.LinkedHashMap;

/**
 * Created by ramakantagrawal on 11/02/17.
 */
public class StairRobot {
    HashMap<Integer, Integer> cache = new LinkedHashMap<Integer, Integer>();
    public static void main(String[] args){
        StairRobot sr = new StairRobot();
        sr.getDistinctWays(100);
    }

    int getDistinctWays(int n){
        if (this.cache.containsKey(n)){
            return this.cache.get(n);
        }
        if(n==1 || n==2){
            return n;
        }else{
            int value = getDistinctWays(n-1) + getDistinctWays(n-2);
            this.cache.put(n, value);
            return value;
        }
    }
}