import java.util.Scanner;
public class Quest01 {

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[][] mat = new int[n][n];

        int dsum = 0; //diagonal sum
        int ndsum = 0; //non-diagonal sum
        //inserting the diagonal elements and summing up
        for(int i=0;i<n;i++){
            mat[i][i] = sc.nextInt();
            dsum += mat[i][i];
        }

        int x=0;
        while(ndsum < dsum){
            x++;
            ndsum = x*n*(n-1); // finding out x as non-diagonal elements  
        }

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n; j++){
                if(i==j) continue;
                mat[i][j] = x;
            }
        }
    }
}
  
