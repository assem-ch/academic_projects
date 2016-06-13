import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int i=0;i<t;i++){
            int t1 = in.nextInt();
            int t2 = in.nextInt();
            int a[] = new int[10];
            for(int j=0;j<10;j++){
                a[j] = in.nextInt();
            }
        for(int seed=t1;seed <=t2;seed+=1){
             Random rand = new Random(seed);
             int r=rand.nextInt(1000);
            //while( r != a[0] ){ r=rand.nextInt(1000);};
            int k=0;
            while( k<10  && r == a[k]){k++; r=rand.nextInt(1000);};
            if (k==10){
                 System.out.print(seed);
                 System.out.print(" "+r);
                for (int j=1; j<10; j++){
                    System.out.print(" "+rand.nextInt(1000));
                };
                System.out.println();
                break;

            }


            }
        }
    }
}