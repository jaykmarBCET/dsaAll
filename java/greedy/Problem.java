package greedy;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Comparator;

public class Problem {
    
    public int activitySelection(int num[][]){
        if(num.length<=0)return 0;
        Arrays.sort(num, (a,b)->a[0]-b[0]);

        
        int end = num[0][1];

        int count =1;
        for(int i =1; i < num.length; i++ ){
            int nextStart = num[i][0];
            if(nextStart>end){
                count++;
                end = num[i][1];
            }

        }
        return count;
    }
    public double fractionalKnopsack(int values[],int weights[],int w){
        int n = values.length;

        double ratio[][] = new double[n][2];
        for(int i=0; i<n; i++){
            ratio[i][0] = i;
            ratio[i][1] = values[i] / (double)weights[i];
        }
        Arrays.sort(ratio, Comparator.comparing(o->o[1]));

        double result = 0;
        int cap = w;

        for(int i=n-1; i>=0; i--){
            int idx = (int) values[i];
            if(cap>=weights[idx]){
                result = values[idx];
                cap -=weights[idx];
            }else{
                result += ratio[i][1]*cap;
                cap = 0;
                break;
            }
        }
        return result;
    }
    public int minAbsoluteDiff(int a[],int b[]){

        int sum = 0;
        Arrays.sort(a);
        Arrays.sort(b);

        for(int i=0; i<a.length; i++){
            sum += Math.abs(a[i]-b[i]);
        }
        return sum;
    }
    public int maxChain(int chains[][]){

        Arrays.sort(chains, Comparator.comparing(o->o[1]));

        int chainLen = 1;
        int endChain = chains[0][1];
        for(int i=1; i<chains.length; i++){
            if(endChain<chains[i][0]){
                chainLen++;
                endChain = chains[i][1];
            }
        }
        return chainLen;
    }
    public int[] indianCoins(int value){
        
        return null;
    }
}
